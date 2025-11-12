#include<bits/stdc++.h>
using namespace std;
string s[200001][3],t[200001][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,x=1,y=1,pd,sum=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][1]>>t[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		while(t[i][1][x]!='b')
		{
			x++;
		}
		while(t[i][2][y]!='b')
		{
			y++;
		}
		pd=x-y;
		for(int j=1;j<=n;j++)
		{
			x=1;
			y=1;
			while(s[i][1][x]!='b')
			{
				x++;
			}	
			while(s[i][2][y]!='b')
			{
				y++;
			}
			if(x-y==pd)
			sum++;
		}
		cout<<sum;
	}
	return 0;
}
