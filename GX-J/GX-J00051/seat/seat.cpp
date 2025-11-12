#include<bits/stdc++.h>
using namespace std;
int c[15][15];
int f[105];
int main()
{freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,z,s=1,r;
cin>>n>>m;
for(int i=1;i<=n*m;i++)
{cin>>f[i];}r=f[1];
for(int j=1;j<=n*m;j++)
{for(int l=j+1;l<n*m;l++){
if(f[j]<f[l]){z=f[j];
f[j]=f[l];
f[l]=z;}}}
for(int i=1;i<=m;i++)
{if(i%2==1)
{for(int j=1;j<=n;j++)
{c[i][j]=f[s];
if(f[s]==r){cout<<i<<" "<<j;return 0;}
s++;}}
else
{for(int j=n;j>=1;j--)
{c[i][j]=f[s];
if(f[s]==r){cout<<i<<" "<<j;return 0;}
s++;}}}
return 0;}
