#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],b[5005],ans=0,c[5005];
const int mod=998244353;
void f(int m,int d,int pre){
    if(d==m){
        int maxn=0,sum=0;
        for(int k=1;k<=d;k++){
            maxn=max(c[k],maxn);
            sum+=c[k];
        }
        if(sum>2*maxn) ans=(ans+1)%mod;
        return;
    }
    for(int i=pre+1;i<=n;i++){
        c[d+1]=a[i];
        f(m,d+1,i);
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    for(int i=3;i<=n;i++){
        f(i,0,0);
    }
    cout<<ans<<endl;
    return 0;
}
