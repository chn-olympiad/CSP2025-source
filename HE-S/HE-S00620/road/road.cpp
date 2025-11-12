#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	long long a,b,c,num=0;
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>a>>b>>c;
			num+=c;
		}
		cout<<num<<endl;
	}
	return 0;
}
