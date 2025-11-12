#include<bits/stdc++.h>
using namespace std;
int n,m,u,a,b,c,sum,a1,a2,a3,a4,a5;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>u;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        sum+=c;
    }
    for(int i=0;i<u;i++)
    {
        cin>>a1>>a2>>a3>>a4>>a5;
    }
    cout<<sum;
    return 0;
}
