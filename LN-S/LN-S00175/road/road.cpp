#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e4+10;

struct edge
{
    int fr,to,val;
    bool operator<(const edge&wow) const
    {
        return val<wow.val;
    }
}ed[N*100];
int cnt=0;
int n,m,k;
int dis[N],fa[N],c[N];
//vector<edge> vec[N];
int aa[15][N];
int ans=0;
int find(int x)
{
    return x==fa[x] ? x : fa[x]=find(fa[x]);
}
int maxx[N];//mei yi ge dian suo lian bian quan zhi de zui da zhi
void merge(int x,int y)
{
    x=find(x),y=find(y);
    fa[x]=y;
}

queue<edge> que;

void kru()
{
    
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    sort(ed+1,ed+m+1);
    for(int i=1;i<=m;i++)
    {
        if(fa[ed[i].fr]!=fa[ed[i].to]) 
        {
            merge(ed[i].fr,ed[i].to),ans+=ed[i].val;
            que.push((edge){ed[i].fr,ed[i].to,ed[i].val});
            maxx[ed[i].fr]=max(maxx[ed[i].fr],ed[i].val);
            maxx[ed[i].to]=max(maxx[ed[i].to],ed[i].val);
        }

    }
    //cout<<ans<<'\n';

}
//   g++ -std=c++14 -O2 wow.cpp -o c
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/




signed main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);


    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    //cout<<"helloworld\n";
    
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        //vec[u].push_back((edge){v,w});
        ed[++cnt].fr=u,ed[cnt].to=v,ed[cnt].val=w;
        //vec[v].push_back((edge){u,w});
    }
    kru();
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            int woww;
            cin>>woww;
            aa[i][j]=woww;
        }
    }
    


    cout<<ans<<'\n';

    return 0;
}