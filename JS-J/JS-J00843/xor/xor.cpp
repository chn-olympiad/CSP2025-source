#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,sum=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(k==1&&a[i]==1)
            sum++;
        if(k==0&&a[i]==0)
            sum++;
    }
    if(k==1)
        cout<<sum;
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]&&a[i]!=0&&i!=n){
                sum++;
                i++;
            }
        }
        cout<<sum;
    }
    return 0;
}
