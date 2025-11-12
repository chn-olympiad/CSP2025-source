#include<bits/stdc++.h>
#define Inf (1ll<<60)
#define inf 0x3f3f3f3f
#define For(i,s,t) for(int i=(s);i<=(t);++i)
#define Down(i,s,t) for(int i=(s);i>=(t);--i)
#define eps 1e-9
typedef long long ll;
typedef unsigned long long ull;
inline int max(int x,int y){return x>y ? x : y;}
inline int min(int x,int y){return x<y ? x : y;}
inline ll max(ll x,ll y){return x>y ? x : y;}
inline ll min(ll x,ll y){return x<y ? x : y;}
inline void ckmn(int &x,int y){x=min(x,y);}
inline void ckmx(int &x,int y){x=max(x,y);}
inline void ckmn(ll &x,ll y){x=min(x,y);}
inline void ckmx(ll &x,ll y){x=max(x,y);}
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0' || '9'<c) f=(c=='-' ? -1 : 1),c=getchar();
    while('0'<=c && c<='9') x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return x*f;
}
using namespace std;
const int N=1e5+100;
int T,n,a[N][3],cnt[10],delta[N],id[3][N];
ll ans=0;
void solve(){
    n=read();
    ans=0;
    For(i,1,n)
        For(j,0,2)
            a[i][j]=read();
    cnt[0]=cnt[1]=cnt[2]=0;
    int mxid;
    For(i,1,n){
        mxid=0;
        For(j,1,2)
            if(a[i][j]>a[i][mxid])
                mxid=j;
        ++cnt[mxid];
        id[mxid][cnt[mxid]]=i;
        ans+=a[i][mxid];
    }
    int mid=(n>>1);
    For(i,0,2)
        if(cnt[i]>mid){
            For(j,1,cnt[i]){
                int u=id[i][j];
                delta[j]=a[u][i]-max(a[u][(i+1)%3],a[u][(i+2)%3]);
            }
            sort(delta+1,delta+cnt[i]+1,less<int>());
            For(j,1,cnt[i]-mid) ans-=delta[j];
            break;
        }
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=read();
    while(T--) solve();
    return 0;
}
