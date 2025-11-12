#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
struct Edge
{
    int u,v,w;
};
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
Edge e[M<<1];
int fa[N];
class FindUnion
{
    private:
        int fa[N];
    public:
        int find_fu(int x){if (x==fa[x]) return x;fa[x]=find_fu(fa[x]);return fa[x];}
        void merge_fu(int x,int y){fa[find_fu(x)]=find_fu(y);}
        void init_fu(int n){for (int i=1;i<=n;i++) fa[i]=i;}
};
FindUnion fu;
void Solve_MST(int n,int m)
{
    fu.init_fu(n);
    for (int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+m+1,cmp);
    int cnt=0;
    long long res=0;
    for (int i=1;i<=m;i++)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if (fu.find_fu(u)!=fu.find_fu(v))
        {
            fu.merge_fu(u,v);
            cnt++,res+=w;
            if (cnt==n-1) break;
        }
    }
    cout<<res<<'\n';
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    //if (k==0)
    //{
        Solve_MST(n,m);
        //return 0;
    //}

    return 0;
}
