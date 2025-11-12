#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fr first
#define sc second
#define mk make_pair
#define pb push_back
const int MAXN=20010,MAXM=1000010,N=15,inf=1e18;
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;}
int n,m,k,fa[MAXN],siz[MAXN],c[N];
pii a[MAXN];
struct side{
    int u,v,w;
    bool operator<(const side&G)const{
        return w<G.w;
    }
}s[MAXM],t[N][MAXN];int it[N];
int fid(int x){return fa[x]==x?x:fa[x]=fid(fa[x]);}
bool mrge(int x,int y){x=fid(x),y=fid(y);
    if(x!=y){
        if(siz[x]>siz[y])swap(x,y);
        fa[x]=y,siz[y]+=siz[x];
    }
    return x!=y;
}
void slv(){
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)s[i].u=read(),s[i].v=read(),s[i].w=read();
    for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
    sort(s+1,s+m+1);
    int tmp=0;
    for(int i=1;i<=m;i++)if(mrge(s[i].u,s[i].v))t[k][++tmp]=s[i];
    for(int i=0;i<k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++)a[j]={read(),j};
        sort(a+1,a+n+1);
        int u=a[1].sc;
        c[i]+=a[1].fr;
        for(int j=2;j<=n;j++)t[i][j-1]={u,a[j].sc,a[j].fr};
    }
    int ans=inf;
    for(int o=0;o<1<<k;o++){
        int sum=0;
        for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
        for(int i=0;i<=k;i++)it[i]=1;
        for(int i=0;i<k;i++)if(o>>i&1)sum+=c[i];
        int cnt=0;
        while(1){
            pair<side,int>tmp={{0,0,inf},k+1};
            for(int j=0;j<=k;j++)if((j==k||o>>j&1)&&it[j]<n)tmp=min(tmp,mk(t[j][it[j]],j));
            it[tmp.sc]++;
            if(mrge(tmp.fr.u,tmp.fr.v))sum+=tmp.fr.w,cnt++;
            if(cnt==n-1)break;
        }
        ans=min(ans,sum);
    }
    printf("%lld",ans);
}
signed main(){
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    slv();
    cerr<<(clock()*1.0)/CLOCKS_PER_SEC<<"s\n";
    return 0;
}