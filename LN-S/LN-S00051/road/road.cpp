#include <bits/stdc++.h>
using namespace std;
int n,m,k,s;
int u[10001];
int v[10001];
int w[1000000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        s+=w[i];
    }
    cout<<s;
    return 0;
}
