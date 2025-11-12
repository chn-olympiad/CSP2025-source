#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
const int N=5e4+10,N2=2e6+10;
const int MOD=998244353;
int n,cnt[N],pow2[N2],r[2][N],c[2][N][N];
ll getpow(int x){
    if(x<=N2)return pow2[x];
    return pow2[x/2]*pow2[x-x/2]%MOD;
}
inline int read(){
    int res=0;
    char ch='#';
    bool flag=false;
    while(!isdigit(ch)){
        if(ch=='-')flag=true;
        ch=getchar();
    }
    while(isdigit(ch)){
        res=(res<<1)+(res<<3)+(ch-48);
        ch=getchar();
    }
    return flag?-res:res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    int maxx=-1;
    int k;
    ll ans=0;
    FOR(i,1,n){
        k=read();
        ++cnt[k];
        if(maxx<k)maxx=k;
    }
    n=maxx;
    pow2[0]=1;
    FOR(i,1,N2)pow2[i]=(pow2[i-1]<<1)%MOD;
    FOR(i,1,n)c[1][0][i]=i;
    int lstsum=0,cursum=0,lstdp=0,curdp=0;
    bool b=0;
    FOR(i,1,n){
        if(cnt[i]==0)continue;
        cursum=lstsum+cnt[i];
        ll tmp=getpow(cursum)*((getpow(cnt[i])-1-cnt[i])%MOD)%MOD;
        ans+=tmp;
        ans%=MOD;
        FOR(j,1,i)c[b][j][i]=(c[!b][j-1][i]+c[!b][j-1][i-1])%MOD;
        FOR(j,1,i-1)FOR(k,1,i/j){
            r[b][i]+=c[b][j][i]*r[!b][i-k*j]%MOD;
            r[b][i]%=MOD;
        }
        curdp=(lstdp*getpow(cnt[i])%MOD-r[b][i]+MOD)%MOD;
        ans+=curdp;
        ans%=MOD;
        lstsum=cursum,lstdp=curdp,b=!b;
    }
    cout<<ans<<endl;
    return 0;
}
