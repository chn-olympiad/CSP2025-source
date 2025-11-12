#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,k,a;
	long long m;
	cin>>n>>m>>k;
	int c[k];
	for(int i=0;i<m;i++)
	{
		cin>>a;
		cin>>a;
		cin>>a;
	}
	m=1000000000;
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int q=0;q<n;q++)
		{
			cin>>a;
			c[i]+=a;
		}
		if(c[i]<m)
		{
			m=c[i];
		}
	}
	cout<<m;
	return 0;
}
