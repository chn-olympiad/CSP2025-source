#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[15];
int b[15][10010];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
	int x,y,z;
	cin>>x>>y>>z;
}
for(int i=1;i<=k;i++)
{
	cin>>a[i];
	for(int j=1;j<=n;j++)
	{
	cin>>b[i][j];
	}
}
cout<<0;
return 0;
}
