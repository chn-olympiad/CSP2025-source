#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10,M = 1e6+10;

int n,m,k;
struct node
{
    int v,w;
};
vector<node> c[N];
int chang[N];
bool v[N];
struct node1
{
    int s,e,l;
};
node1 b[M];

bool cmp(node1 n1, node1 n2)
{
    return n1.l < n2.l;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1; i<= m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        b[i].s = x,b[i].e = y,b[i].l = z;
    }
    for(int i = 1; i<= k; i++)
    {
        cin>>chang[i];
        for(int j = 1; j<= n; j++)
        {
            int x;
            cin>>x;
        }
    }
    int ans = 0;
    sort(b+1,b+m+1,cmp);
    for(int i = 1; i<= m; i++)
    {
        if(!v[b[i].s] || !v[b[i].e])
        {
            ans += b[i].l;
            v[b[i].s]=1;
            v[b[i].e]=1;
        }
    }
    cout<<ans;
    return 0;
}
