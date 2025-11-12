#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=1e4+10,M=1e6+10,K=10+10,mod=1e9+7;
inline int read(){
    int v=0;
    bool f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
        if(ch=='-')f=1;
    }
    while(ch>='0'&&ch<='9'){
        v*=10;
        v+=ch-'0';
        ch=getchar();
    }
    return (f?-v:v);
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        write(x/10);
        putchar(x%10+'0');
    }
    else putchar(x+'0');
}
int n,m,k;
struct edge{
    int u,v,w;
    int ip=0,w2;
}e[M];
bool asd(edge x,edge y){
    return x.w<y.w;
}
int c[N],a[K][N];
int fa[N];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    fa[y]=x;
    return ;
}
bool used[K],can[N][N];
vector<int>chedge[K];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    m=read();
    k=read();
 //   cerr<<n<<m<<k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        e[i]={u,v,w};
        can[u][v]=1;
        can[v][u]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(!can[i][j])e[++m]={i,j,LLONG_MAX};
    int ans=0;
    for(int i=1;i<=k;i++){
        c[i]=read();
        ans+=c[i];
        for(int j=1;j<=n;j++){
            a[i][j]=read();
        }
    }
//    write(m);
//    puts("");
    int t=m;
    for(int i=1;i<=m;i++){
        int res=LLONG_MAX,ip=0;
        for(int j=1;j<=k;j++){
            int now=a[j][e[i].u]+a[j][e[i].v];
            if(now<res){
                res=now;
                ip=j;
            }
        }
        if(res<e[i].w){
            e[t++]=e[i];
            e[t].w=res;
            e[t].ip=ip;
            //chedge[ip].push_back(i);
            //cerr<<i<<endl;
        }
    }
    m=t;
    sort(e+1,e+m+1,asd);
    for(int i=1;i<=m;i++){
        if(find(e[i].u)^find(e[i].v)){
            ans+=e[i].w;
            used[e[i].ip]=1;
            merge(e[i].u,e[i].v);
        }
    }
    for(int i=1;i<=k;i++)if(!used[i])ans-=c[i];
    write(ans);
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

it seems to do with dp.
but i can't think how...
*/