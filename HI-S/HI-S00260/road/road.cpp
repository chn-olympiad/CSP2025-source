#include<bits/stdc++.h>
using namespace std;
int s=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,t;
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a>>a>>a; 
	}
	for(int i=1;i<=m;i++)
	{
		for(int i=1;i<=n;i++)
		{
			int ss;
			cin>>ss;
			s+=ss; 
		}
	}
	cout<<s;
	
	
	return 0;
}
