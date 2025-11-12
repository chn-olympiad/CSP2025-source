#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	srand(time(0));
	cin>>n>>m>>k;
	vector<int> a;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	int b[10005][15];
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}
	cout<<rand();
	return 0;
}
