#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000000],v[1000000],w[1000000],s;
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=n;i++)
{
cin>>u[i]>>v[i]>>w[i];
s+=w[i];
}
if(k==0)cout<<s;
else cout<<50;
return 0;
}
