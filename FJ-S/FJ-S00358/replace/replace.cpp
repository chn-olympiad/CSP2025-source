#include <bits/stdc++.h >
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	int n,m;
	string s1;
	cin>>n>>m>>s1;
	int c[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int s[n];
	for(int i=1;i<=n;i++)
	{
		s[i]=int(s1[i]);
	}
	int s2;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==0)
		{
			s2++;
		}
		for(int j=1;j<=n;j++)
		{
			if(c[i]>=s2)
			{
				s2++;
			}
		}
	}
	cout<<2;
	return 0;
}
