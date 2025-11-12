#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,a[N],k,v[N],ans,f;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f=1;
    }
    if(k==0&&f==0){
        cout<<n/2;
        exit(0);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            long long sum=0;
           for(int si=j;si<=i;si++){
                if(v[si]==1){
                    sum=-1;
                    break;
                }
                sum+=sum^a[si];
            }
            if(sum==k){
                ans++;
                for(int si=j;si<=i;si++)v[si]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
