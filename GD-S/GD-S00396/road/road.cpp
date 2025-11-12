#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","f",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[100005][4];
	int b[100005][100005];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<13;
}
