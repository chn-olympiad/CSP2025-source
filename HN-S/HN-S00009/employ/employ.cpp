#include<bits/stdc++.h>
using namespace std;
int c[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
		{
			cnt++;
		}
	}
	if(s.find('0')==-1)
	{
		if(s.size()-cnt>=m)
		{
			int ans=1;
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=998244353;
			}
			cout<<ans;
		}
		else
		{
			cout<<0;
		}
	}
	else if(n<=10)
	{
		int pos[n+2];
		for(int i=1;i<=n;i++)
		{
			pos[i]=i;
		}
		do{
			int cnt=0;
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i]=='0')
				{
					cnt++;
				}
				else
				{
					ans++;
				}
			}
		}while(next_permutation(pos+1,pos+n+1));
	}
	return 0;
}
