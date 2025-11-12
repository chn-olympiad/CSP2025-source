#include<bits/stdc++.h>
using namespace std;
int c[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long sum=1;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==1)
	{
		
	}else 
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				cout<<0;
				return 0;
			}
		}
		
	}
	return 0;
}
