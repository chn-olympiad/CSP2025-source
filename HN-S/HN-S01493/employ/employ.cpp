#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	int q,ans=1;
	string s;
	int shu=0;
	int c[1000];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
		{
			shu++;
		}
		
	}
	if(n-shu<m)
	{
		cout<<0;
		return 0;
	}
	else 
	{
		for(int i=1;i<n;i++)
		{
			ans=ans*q;
			q++;
		}
	}
	cout<<q;
	return 0;
}
