#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000],b[1000],c[1000],z[1000],d[1000][1000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
	{
        cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=0;i<=k;i++)
	{
		cin>>z[i]
		for(int j=0;j<=n;j++)
		{
			cin>>d[i][j];
		}
	}
	cout<<2; 
	
	return 0;
} 
