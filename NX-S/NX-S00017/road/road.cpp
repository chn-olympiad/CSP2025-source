#include <bits/stdc++.h>
using namespace std;
struct R{
    int x,y,q;
};
R alf[1000005];
int n,m,k,a[105][105],fa[100050];
bool comp(R a,R b)
{
    return a.q<b.q;
}
void cs(int s)
{
    for (int i=1;i<=s;i++)
    {
        fa[i]=i;
    }
    return ;
}
int xfind(int wz)
{
    if (fa[wz]==wz)
    {
        return wz;
    }
    return fa[wz]=xfind(fa[wz]);
}
void xmarge(int a,int b)
{
    a=xfind(a);
    b=xfind(b);
    fa[a]=b;
    return ;
}
void Kru()
{
    cs(n);
    int cnt=0,res=0;
    for (int i=1;i<=m;i++)
    {
        if (xfind(alf[i].x)!=xfind(alf[i].y))
        {
            xmarge(alf[i].x,alf[i].y);
            res+=alf[i].q;
            cnt++;
        }
        if (cnt==n-1)
        {
            cout<<res;
            return ;
        }
    }
    return ;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        cin>>alf[i].x>>alf[i].y>>alf[i].q;
    }
    for (int i=1;i<=k;i++)
    {
        for (int j=0;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    sort(alf+1,alf+1+m,comp);
    Kru();
}
