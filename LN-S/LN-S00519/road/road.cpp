#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=10005,M=1000005;
int n,m,k,fee[13],fa[N];
struct edge{
    int u,v,w;
    bool operator<(const edge&rhs)const{
        return w<rhs.w;
    }
}e[M];
vector<edge>q[1<<11],Em[13];

int lowbit(int x){
    return x&(-x);
}

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;i++){
        cin>>fee[i];
        for(int j=1,xX;j<=n;j++){
            cin>>xX;
            Em[i].push_back((edge){i+n,j,xX});
        }
        sort(Em[i].begin(),Em[i].end());
    }
    sort(e+1,e+m+1);
    int cnt=0,ans=0,ret=0;
    for(int i=1;i<=m;i++){
        int fu=find(e[i].u),fv=find(e[i].v);
        if(fu==fv)continue;
        fa[fu]=fv;
        q[0].push_back(e[i]);
        ans+=e[i].w;
        cnt++;
        if(cnt==n-1)break;
    }
    ret=ans;
    for(int S=1;S<(1<<k);S++){
        // S-lowbit(S) -> S
        // q[S] <- q[ S-lowbit(S) ] & Em[ lowbit(S) ]
        int Sk=__builtin_popcount(S);
        int h1=0,h2=0,x=lowbit(S),y=__builtin_ctz(S)+1;
        for(int i=1;i<=n+k;i++)fa[i]=i;
        ans=cnt=0;
        while(cnt!=(n+Sk)-1){
            if(h1<q[S-x].size()&&q[S-x][h1]<Em[y][h2]){
                int fu=find(q[S-x][h1].u),fv=find(q[S-x][h1].v);
                h1++;
                if(fu==fv)continue;
                fa[fu]=fv;
                q[S].push_back(q[S-x][h1-1]);
                ans+=q[S-x][h1-1].w;
                cnt++;
            }else{
                int fu=find(Em[y][h2].u),fv=find(Em[y][h2].v);
                h2++;
                if(fu==fv)continue;
                fa[fu]=fv;
                q[S].push_back(Em[y][h2-1]);
                ans+=Em[y][h2-1].w;
                cnt++;
            }
        }
        for(int i=1;i<=k;i++)
            if(S&(1<<(i-1)))ans+=fee[i];
        ret=min(ret,ans);
    }
    cout<<ret<<'\n';
}
