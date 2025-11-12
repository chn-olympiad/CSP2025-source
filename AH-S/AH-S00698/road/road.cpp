#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,s=0;
    cin>>n>>m>>k;
    int u[m],v[m],w[m],a[n+1],b[m],c[k];
    for(int i=0;i<m;i++) cin>>u[i]>>v[i]>>w[i];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<=n;j++) cin>>a[j];
        sort(a,a+n);
        c[i]=a[0]+a[1]+a[2];
    }
    for(int i=0;i<m;i++) b[i]=w[i];
    for(int i=0;i<k;i++) b[i+m]=c[i];
    sort(b,b+m+k);
    for(int i=0;i<m-1;i++) s+=b[i];
    cout<<s;
    return 0;
}
