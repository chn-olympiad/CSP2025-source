#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum=0,p=0,q=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		sum+=c;
	}
	cout<<(sum+n)/2;
	return 0;
}
