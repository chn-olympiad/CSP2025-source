#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FILE_IO
// #define DEBUG
// pass
// time optimization O(2^{k}a(n+k)m), but very quick
int n,m,k,c[15];
bool cho[20005];
struct Edge
{
    int u,v,w;
};
vector<Edge> ed;
int bf[20005];
int getf(int x)
{
    return x==bf[x]?x:bf[x]=getf(bf[x]);
}
signed main()
{
    #ifdef FILE_IO
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    #define endl '\n'
    #endif // FILE_IO
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ed.push_back((Edge){u,v,w});
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            int w;
            cin>>w;
            ed.push_back((Edge){n+i,j,w});
        }
    }
    sort(ed.begin(),ed.end(),[&](Edge a,Edge b)->bool
         {
             return a.w<b.w;
         });
    vector<int> vec;
    for(int ch=0;ch<(1<<k);ch++)
        vec.push_back(ch);
    mt19937 rd(114500179);
    shuffle(vec.begin(),vec.end(),rd);
    int finalans=0x3f3f3f3f3f3f3f3fll;
    // Maybe it can be faster by shuffle the order?
    for(int ch:vec)
    {
        int ans=0;
        for(int i=1;i<=n+k;i++)
            cho[i]=false;
        for(int i=1;i<=n;i++)
            cho[i]=true;
        for(int i=1;i<=k;i++)
            if(ch&(1<<(i-1)))
                cho[n+i]=true,ans+=c[i];
        for(int i=1;i<=n+k;i++)
            bf[i]=i;
        for(Edge edd:ed)
            if(cho[edd.u]&&cho[edd.v]&&getf(edd.u)!=getf(edd.v))
            {
                bf[getf(edd.u)]=getf(edd.v);
                ans+=edd.w;
                if(ans>=finalans) // A small trick, but very quick
                    break;
            }
        finalans=min(finalans,ans);
    }
    cout<<finalans<<endl;
    return 0;
}
