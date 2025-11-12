#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int read(){
    int res=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')res=(res<<3)+(res<<1)+(c-'0'),c=getchar();
    return res*f;
}
void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const int maxn=2e4+100;
const int maxm=1e6+5;
const int mod=1e9+7;
int n,m,k,a[11][maxn],pid[11][maxn],Tmp,val[2005],vis[2005],ans;
struct ed{int u,v,w;}e[13][maxn];int ecnt;//
int edu[maxm],edv[maxm],edw[maxm],id[maxm],fa[maxn];
bool cmp2(int x,int y){return a[Tmp][x]<a[Tmp][y];}
bool cmp(int x,int y){return edw[x]<edw[y];}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(int s){
    if(vis[s])return;vis[s]=1;
    int res=0,cnt=0;
    for(int i=0;i<k;i++)res=res+((s>>i)&1)*val[i],cnt+=((s>>i)&1);
    ecnt=0;
    for(int i=1;i<=n+k;i++)fa[i]=i;
    for(int i=1;ecnt<n+cnt-1;i++){
        int x=e[cnt][i].u,y=e[cnt][i].v;
        // cerr<<x<<' '<<y<<' '<<e[cnt][i].w<<endl;
        if(find(x)!=find(y)){
            ecnt++;
            e[cnt][ecnt]={x,y,e[cnt][i].w};res+=e[cnt][ecnt].w;
            fa[find(x)]=find(y);
        }
    }
    // cerr<<endl;
    ans=min(ans,res);
    for(int i=0;i<k;i++){
        if(!((s>>i)&1)&&!vis[s|(1<<i)]){
            for(int p=1,q=1,t=1;p<=n+cnt-1||q<=n;t++){
                if(p>n+cnt-1||(q<=n&&a[i][pid[i][q]]<e[cnt][p].w)){
                    e[cnt+1][t]={i+n+1,pid[i][q],a[i][pid[i][q]]};q++;
                }else{
                    e[cnt+1][t]={e[cnt][p].u,e[cnt][p].v,e[cnt][p].w};p++;
                }
            }
            dfs(s|(1<<i));
        }
    }
}
void solve(){
    n=read(),m=read(),k=read();ans=mod*mod;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        edu[i]=read();edv[i]=read();edw[i]=read();
        id[i]=i;
    }
    sort(id+1,id+m+1,cmp);
    for(int i=1;i<=m;i++){
        int x=edu[id[i]],y=edv[id[i]];
        if(find(x)!=find(y)){
            e[0][++ecnt]={x,y,edw[id[i]]};
            fa[find(x)]=find(y);
        }
    }
    for(int i=0;i<k;i++){
        val[i]=read();
        for(int j=1;j<=n;j++)a[i][j]=read(),pid[i][j]=j;
        Tmp=i;sort(pid[i]+1,pid[i]+n+1,cmp2);
    }
    dfs(0);
    write(ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int T=1;
    while(T--)solve();
    return 0;
}