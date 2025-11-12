#include <bits/stdc++.h>
using namespace std;
int n,m,k,sum1,sum2,minn=0;
int u[1005],v[1005],w[1005],c[1005],a[1005];
int main()
{
freopen("road","in",stdin);
freopen("road","out",stdout);
cin >>n>>m>>k;
for(int i=1;i<=m;i++)
{
    cin >>w[i];
    sum1+=w[i];
}
for(int i=1;i<=m;i++)
{
    cin >>u[i]>>v[i]>>w[i];
    for(int j=1;j<=k;j++)
    {
        cin >>c[j];
        sum2+=c[j];
        for(int l=j;l<=n;l++)
        {
            cin>>a[l];
            sum2+=a[l]*a[i];
        }
    }
}
int num=min(sum1,sum2);
cout <<num;
return 0;
}
