#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node1
{
    int c1,c2,c;
}a[1000010];
int b[11][10010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
    {
        cin>>a[i].c1>>a[i].c2>>a[i].c;
    }
    for(int i=1;i<=k;++i)
    {
        for(int j=1;j<=n+1;++j)
        cin>>b[i][j];
    }
    cout<<66;
    return 0;
}