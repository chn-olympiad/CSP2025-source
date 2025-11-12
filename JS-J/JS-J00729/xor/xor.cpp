#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],k,f,x;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (k==0){
        cout<<n;
        return 0;
    }
    for (int i=1;i<=n;i++){
        long long flag=0,cnt=0;
        for (int j=i;j<=n;j++){
            for (int s=i;s<=j;s++){
                f;
                if (i==j){
                    f=a[s];
                    break;
                }
                else f=f^a[s];
            }
            if (f==k) i=j+1;
            else{
                flag=1;
                break;
            }
            if (flag==0) cnt++;
        }
        x=cnt;
        x=max(x,cnt);
    }
    cout<<x;
    return 0;
}
