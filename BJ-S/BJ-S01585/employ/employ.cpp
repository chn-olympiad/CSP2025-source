#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define pi pair<int,int>
#define p1 first
#define p2 second
#define m_p make_pair
#define p_b push_back
using namespace std;
typedef long long ll;
const int maxn=2e5+10,mod=998244353;
inline ll read(){
    ll x=0;short t=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}
int n,m,c[505],cnt[505],f[505][505],g[505][505],jc[505];
string s;
inline int add(int x,int y){if((x+=y)>=mod)x-=mod;return x;}
void slv(){
    n=read(),m=read();cin>>s;s=" "+s;
    jc[0]=1;up(i,1,n)jc[i]=jc[i-1]*1llu*i%mod;
    up(i,1,n)++cnt[read()];
    up(i,1,n)cnt[i]+=cnt[i-1];
    f[0][0]=1;
    up(i,1,n){
        memset(g,0,sizeof(g));
        if(s[i]=='0'){
            up(j,0,i-1)up(k,0,i-1)g[j+1][k]=f[j][k];
        }else{
            up(j,0,i-1)up(k,0,i-1){
                g[j][k]=add(g[j][k],f[j][k]);
                if(cnt[j]>=k){
                    int s=f[j][k]*1llu*(cnt[j]-k)%mod;
                    g[j][k+1]=add(g[j][k+1],mod-s);
                    g[j+1][k+1]=add(g[j+1][k+1],s);
                }
            }
        }
        memcpy(f,g,sizeof(g));
    }
    int res=0;
    up(j,0,n-m){
        up(k,0,n){
            int p=f[j][k]*1llu*jc[n-k]%mod;
            res=add(res,p);
        }
    }
    cout<<res;
}
int main(){
    freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
    slv();
    return 0;
}