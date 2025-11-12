#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],b[N],c[N],d[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=k;i++)
    {
        int w;
        cin>>w;
        for(int j=1;j<=n;j++)
            cin>>d[j];
        for(int j=1;j<=m;j++)
        {
            int wz=w+d[a[j]]+d[b[j]];
            if(wz<c[j])
                c[j]=wz;
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++)
        ans+=c[i];
    cout<<ans;
    return 0;
}
