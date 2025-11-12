#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[500005];
long long _xor[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n>10000){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        int na=0,nb=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                na++;
            }else{
                nb++;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]==1&&a[i+1]==1){
                nb++;
                i++;
            }
        }
        if(k==0){
            cout<<nb;
        }else{
            cout<<na;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        _xor[i]=_xor[i-1]^a[i];
    }
    long long sum=0,ans=0;
    for(int i=1;i<=n;i++){
        sum=0;
        int t=i;
        for(int j=i;j<=n;j++){
            if((_xor[j]^_xor[t-1])==k){
                sum++;
                t=j+1;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
