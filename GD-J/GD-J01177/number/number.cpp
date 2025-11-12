#include<bits/stdc++.h>
using namespace std;
int f[15][15];
signed main()
{
	freopen("seat.in.txt","r",stdin);
	freopen("seat.out.txt","w",stdout);
	
	int m,n;
	cin>>n>>m;
	set<int> r;
	vector<vector<int>> f(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>f[i][j];
			r.insert(f[i][j]);
		}
	vector<int> a(r.begin(),r.end());
	for(int i=0;i<=a.size();i++)
		cout<<a[i]<<' ';	
	
	fclose(stdin);	fclose(stdout);
	return 0;
}
