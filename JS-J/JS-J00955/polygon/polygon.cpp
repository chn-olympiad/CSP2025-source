#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005];
int pq(int a,int b){
    int ans=1;
    while(b){
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    a[0]=1;
    bool k=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1]) k=false;
    }
    if(k){
        cout<<((1<<n)+2*mod-1-pq(n,n+1)*pq(2,mod-2))%mod;
        return 0;
    }
    int ans=0;
    for(int i=7;i<(1<<n);i++){
        int k=i,m=1,cnt=0,maxn=0;
        while(k){
            if(k&1) cnt+=a[m],maxn=max(maxn,a[m]);
            m++,k>>=1;
        }
        if(cnt>2*maxn) ans++;
    }
    cout<<ans;
    return 0;
}
