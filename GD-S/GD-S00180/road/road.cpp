#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long int n,m,k;
	cin>>n>>m>>k;
	for(long long int i=1;i<=n;i++)
	{
		long long int a,b,c;
		cin>>a>>b>>c;
		s.insert(c);
	} 
	for(long long int i=1;i<=k;i++)
	{
		long long int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
	}
	long long int ans=0,sum=0; 
	for(auto i:s)
	{
		ans++;
		sum+=i;
		if(ans==2)
		{
			break ;
		}
	}
	cout<<sum;
}
