#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353,inf=0x3f3f3f3f3f3f3f3f;
const int N=1e4+10,M=2e5+10;
mt19937 rnd(time(0));
int n,m,k;
int a[20][N],c[N];
struct E{
    int u,v,w;
};vector<E>e,mst;
vector<int>b;
int cmp(E p,E q){return p.w<q.w;}
int fa[N+10];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
vector<pair<int,int>>e1[N*11],e2[N*11];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin >> n >> m>> k;
    while(m--)
    {
        int u,v,w;cin >> u >> v >> w;
        e.push_back({u,v,w});
    }
    sort(e.begin(),e.end(),cmp);
    for ( int i = 1 ; i <= n ; i++ )fa[i]=i;
    for ( auto x:e )
    {
        int u=x.u,v=x.v,w=x.w;
        u=find(u),v=find(v);
        if(u==v)continue;
        mst.push_back(x);
        fa[u]=v;
        b.push_back(w);
    }
    for ( int i = 1 ; i <= k ; i++ )
    {
        cin >> c[i];
        for ( int j = 1 ; j <= n ; j++ )
        {
            cin >> a[i][j];
            b.push_back(a[i][j]);
        }
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for ( auto x:mst )
    {
        int u=x.u,v=x.v,w=x.w;
        w=lower_bound(b.begin(),b.end(),w)-b.begin()+1;
        e1[w].push_back({u,v});
    }
    for ( int i = 1 ; i <= k ; i++ )
        for ( int j = 1 ; j <= n ; j++ )
            a[i][j]=lower_bound(b.begin(),b.end(),a[i][j])-b.begin()+1;
    int ans=inf;
    for ( int i = 0 ; i < (1ll<<k) ; i++ )
    {
        int cnt=0;
        for ( int j = 1 ; j <= n+k ; j++ )fa[j]=j;
        for ( int j = 1 ; j <= b.size() ; j++ )e2[j].clear();
        for ( int j = 1 ; j <= k ; j++ )
            if((i>>j-1)&1)
            {
                cnt+=c[j];
                for ( int k = 1 ; k <= n ; k++ )
                    e2[a[j][k]].push_back({j+n,k});
            }
        for ( int j = 1 ; j <= b.size() ; j++ )
        {
            for ( auto x:e1[j] )
            {
                int u=x.first,v=x.second;
                u=find(u),v=find(v);
                if(u==v)continue;fa[u]=v;cnt+=b[j-1];
                // cerr << "add " << x.first << " " << x.second << " " << b[j-1] << endl;
            }
            for ( auto x:e2[j] )
            {
                int u=x.first,v=x.second;
                u=find(u),v=find(v);
                if(u==v)continue;fa[u]=v,cnt+=b[j-1];
                // cerr << "add " << x.first << " " << x.second << " "<< b[j-1] << endl;
            }
        }
        // cerr << i << " " << cnt << endl;
        ans=min(ans,cnt);
    }
    cout << ans << endl;
	return 0;
 } 
/*
一个直观的想法就是直接枚举改造哪些乡村然后跑 MST
但是这样复杂度是 O(m2^k) 的，直接完蛋。
64 分，拼上 A 72 分。
性价比挺高，先去看其他题吧。

猜一个东西，如果我们会做删掉一个点求出剩下的 MST，则求删掉两个点的时候先删哪个没影响。
但是就算这个是对的我也什么也不会做。

直接对原图做 MST，然后枚举改造哪些乡村？
我草这不就把 m 降到 nk 了？？？
O(nk2^k)
*/