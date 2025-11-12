#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5005;
int n,a[N],pre[N],ans,maxn,dig,supans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) dig++;
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
                if(j==i+1){
                    maxn=max(a[i],a[j]);
                }
            int cnt=pre[j]-pre[i-1];
            maxn=max(maxn,a[j]);
            if(cnt>2*maxn){
                   // cout<<i<<' '<<j<<endl;
                ans++;
                ans%=mod;
            }
        }
    }
    if(n<500){
        cout<<ans;
        return 0;
    }
    else {
        int upans=1;
    for(int i=n;i>=1;i--){
        upans*=i;
        supans+=upans;
        supans%=mod;
    }
        cout<<supans-dig;
    }
    return 0;
}
