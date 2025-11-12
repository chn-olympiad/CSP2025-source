#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>m>>n;
	string s[n];
	int c[n]={};
	int p=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];	
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];	
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=="0")
		{
			n--;
			for(int j=i;j<=n;j++)
			{
				c[i]=c[i]-1;
				if(c[i]==0)
				{
					n--;
				}
			}
		}	
		else
		{
			p++;
		}
		if(p==m||n==m)
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

