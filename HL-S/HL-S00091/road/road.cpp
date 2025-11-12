#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,m,k;
cin>>n>>m>>k;
for(int i=1;i<=m;i++)
{
	int u,v;
	cin>>u>>v>>a[u][v];
}
int h=0;
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=n;j++)	h+=a[i][j];
}
cout<<h<<endl;
return 0;
}
// i have any ways to approach this goals,but i decide to give up.
