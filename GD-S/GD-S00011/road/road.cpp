#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,q,cnt=0;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		cnt+=w;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
