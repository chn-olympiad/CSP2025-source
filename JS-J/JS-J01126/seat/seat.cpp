#include <bits/stdc++.h>
using namespace std;
const int DATA=100;
/*
char vis[DATA]={};
dfs()
{
    if()
    {
    }
    else
    {
        vis[i]=1;
        dfs()
        vis[i]=0;
    }
    return;
}
*/
/*
struct xxx{

};
xxx ecm[DATA]={};
*/
/*
xx P()
{
    return xx;
}
*/
int points[DATA]={};
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>points[i];
    }
    int finding=points[0];
    sort(points,points+n*m,greater<int>());
    int pos=(find(points,points+n*m,finding)-&points[0])+1;
    int optm=0,optn=0;
    optm=(pos%n==0?pos/n:pos/n+1);
    if(optm%2==1)
    {
        optn=(pos%n==0?n:pos%n);
    }
    else
    {
        optn=(pos%n==0?1:n-(pos%n)+1);
    }
    cout<<optm<<' '<<optn;
    return 0;
}