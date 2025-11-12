#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const long long mod = 998244353;
const long long inf = 1e18;
int n , m;
int k;
vector<int>a[10015] , w[10015];
vector<int>a2[10015] , w2[10015];
int c[15];
struct node{
    int u , v , w;
};
struct cmp{
    bool operator()(node s1 , node s2) const{
        return s1.w > s2.w;
    }
};
int cnt;
void mintree()
{
    cnt = 0;
    priority_queue<node , vector<node> , cmp>q;
    bitset<10015>vis;
    for(int i = 1 ; i <= 10011 ; i++)vis[i] = 0;
    vis[1] = 1;
   // cout<<"mintree: "<<a[1].size()<<endl;
    for(int i = 0 ; i < a[1].size() ; i++)
    {
        if(a[1][i] <= n)q.push((node){1 , a[1][i] , w[1][i]});
  //      cout<<1<<' '<<a[1][i]<<' '<<w[1][i]<<endl;
    }
    int u , v , ww;
    while(!q.empty())
    {
        if(vis[q.top().v])
        {
            q.pop();
            continue;
        }
        u = q.top().u;
        v = q.top().v;
        ww = q.top().w;
        a2[u].push_back(v) , w2[u].push_back(ww);
        a2[v].push_back(u) , w2[v].push_back(ww);
//        cout<<u<<' '<<v<<' '<<ww<<endl;
        q.pop();
        cnt += ww;
        vis[v] = 1;
            for(int i = 0 ; i < a[v].size() ; i++)
            {
                if(!vis[a[v][i]])
                {
                    q.push((node){v , a[v][i] , w[v][i]});
                }
            }
    }
    return ;
}
void mintree2(int t)
{
//    cout<<"mintree2: "<<t<<endl;
    cnt = 0;
    priority_queue<node , vector<node> , cmp>q;
    bitset<10015>vis;
    for(int i = 1 ; i <= 10011 ; i++)vis[i] = 0;
    vis[1] = 1;
    for(int j = 1 ; j <= k ; j++)
    {
        if(!(t & (1 << (j - 1))))vis[n + j] = 1;
        else cnt += c[j];
//        cout<<j<<':'<<(t & (1 << (j - 1)))<<' '<<vis[n + j]<<endl;
    }
   // cout<<"mintree: "<<a[1].size()<<endl;
    for(int i = 0 ; i < a2[1].size() ; i++)
    {
        q.push((node){1 , a2[1][i] , w2[1][i]});
//        cout<<1<<' '<<a2[1][i]<<' '<<w2[1][i]<<endl;
    }
    int u , v , ww;
    while(!q.empty())
    {
        if(vis[q.top().v])
        {
            q.pop();
            continue;
        }
        u = q.top().u;
        v = q.top().v;
        ww = q.top().w;
//        cout<<u<<' '<<v<<' '<<ww<<endl;
        q.pop();
        cnt += ww;
        vis[v] = 1;
        for(int i = 0 ; i < a2[v].size() ; i++)
        {
            if(!vis[a2[v][i]])
            {
                q.push((node){v , a2[v][i] , w2[v][i]});
            }
        }
    }
    return ;
}
signed main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    cin>>n>>m>>k;
    int u , v , ww;
    for(int i = 1 ; i <= m ; i++)
    {
        cin>>u>>v>>ww;
 //       cout<<u<<' '<<v<<' '<<ww<<endl;
        a[u].push_back(v) , w[u].push_back(ww);
        a[v].push_back(u) , w[v].push_back(ww);
    }
    mintree();
//    cout<<cnt<<endl;
    for(int i = 1 ; i <= k ; i++)
    {
        cin>>c[i];
        for(int j = 1 ;  j <= n ; j++)
        {
            cin>>ww;
            a2[i + n].push_back(j) , w2[i + n].push_back(ww);
            a2[j].push_back(i + n) , w2[j].push_back(ww);
        }
    }
    int ans = cnt;
    for(int i = 1 ; i < 1 << (k) ; i++)
    {
        mintree2(i);
        ans = min(ans , cnt);
    }
    cout<<ans;
    return 0;
}
