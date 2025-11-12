#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k,s=0;
    cin>>n>>m>>k;
    long long a[m+1],b[m+1],c[m+1];
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(c[i]==4||c[i]==5)
            s+=c[i];
    }
    long long d[k+1],e[n+1];
    for(int i=1;i<=k;i++)
    {
        cin>>d[i];
        for(int j=1;j<=n;j++)
        {
            cin>>e[j];
            if(d[i]==1&&e[j]==1)
                s+=d[i]+e[j];
            if(d[i]==1&&e[j]==2)
                s+=e[j];
        }
    }
    cout<<s<<endl;
    return 0;
}
