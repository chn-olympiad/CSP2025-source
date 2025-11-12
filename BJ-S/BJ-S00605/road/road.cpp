#include <bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int u[1000010],v[1000010],w[1000010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        sum+=w[i];
    }
    sort(w+1,w+1+m,greater<int>());
    sum-=w[1];
    cout<<sum<<endl;
    return 0;
}
