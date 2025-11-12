#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,M=2e6+5;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
int n,m,k,cnt,stk[20],top;
int ans,a[N][20],prc[20];
unordered_map<int,int>f,siz;
struct edge{
    int u,v,w;
    friend bool operator < (edge x,edge y){
        return x.w<y.w;
    }
}p[M];
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(x);
}
void merge(int x,int y){
    int xx=find(x),yy=find(y);
    if(xx==yy) return ;
    if(siz[xx]>siz[yy]) swap(xx,yy);
    f[xx]=yy,siz[yy]+=siz[xx];
    return ;
}
inline int K(int cc,int sum){
    int res=0;
    sort(p+1,p+cnt+1);
    for(int i=0;i<=n+k;i++) f[i]=i,siz[i]=1;
    int num=0;
    for(int i=1;i<=cnt && num<n+cc-1;i++){
        int x=find(p[i].u),y=find(p[i].v);
        if(x==y) continue;
        num++;
        res+=p[i].w;
        merge(p[i].u,p[i].v);
    }    
    return res+sum;
}
inline void dfs(int x){
    if(x==k+1){
        int pos=cnt,sum=0;
        for(int i=1;i<=top;i++){
            sum+=prc[stk[i]];
            for(int j=1;j<=n;j++){
                p[++cnt]={n+stk[i],j,a[j][stk[i]]};
            }
        }
        ans=max(ans,K(top,sum));
        cnt=pos;
        return ;
    }
    stk[++top]=x;
    dfs(x+1);
    --top;
    dfs(x+1);
    return ;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        p[++cnt]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        cin>>prc[i];
        for(int j=1;j<=n;j++){
            cin>>a[j][i];
        }
    }
    dfs(1);
    cout<<ans<<'\n';
    return 0;
}
