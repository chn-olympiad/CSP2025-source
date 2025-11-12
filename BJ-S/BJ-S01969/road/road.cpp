#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k;
int u[N],v[N],w[N],c[N],a[N][10];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    if(m==1)
    {
        cout<<w[m];
        return 0;
    }
    else
    {
        for(int i=1;i<=m;i++)
            ans+=w[i];
    }
    cout<<ans;



    return 0;
}
