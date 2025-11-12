#include<bits/stdc++.h>
using namespace std;
struct road
{
int beg;
int end;
int cost;
}a[100005];
int b[1000][1000],f[1000];
int main()
{
	freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,m,k,sum=0;
cin>>n>>m>>k;
for(int i=1;i<=m;i++)
{
cin>>a[i].beg>>a[i].end>>a[i].cost;}
if(k==0)
{
for(int i=1;i<=n;i++)
{
sum+=a[i].cost;
}
cout<<sum;
return 0;
}
for(int j=1;j<=k;j++)
{
for(int i=0;i<=n;i++)
{
cin>>b[j][i];
}
}
for(int i=1;i<=m;i++)
{
sum+=b[i][0];
}
cout<<sum;
return 0;
}
