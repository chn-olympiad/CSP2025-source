#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,s,c,p;
	int num1;
	int num2;
	num1=0;
	num2=0;
	int total;
	int all=1;
	cin>>m;
	cin>>n;
	int s0[51][4];
	for(int i=1;i<=n;i++)
	{
		s0[i][1]=0;
		s0[i][2]=0;
		s0[i][3]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		s0[i][1]=s;
		cin>>c;
		s0[i][2]=c;
	}
	for(int i=1;i<=n;i++)
	{
	if(s0[i][1]!=0)
	{
		num1=num1+1;
		s0[i][2]=0;
	}
	else
	{
		s0[i+1][3]=s0[i+1][3]+1;
	}
	}
	for(int i=1;i<=n;i++)
	{
		if(s0[i][2]<s0[i][3])
		{
			num2=num2+1;
		}	
	}
	total=num1+num2;
	all=1;
	for(int i=0;i<=(total-1);i++)
	{
		all=all*(total-i);
	}
	p=total%998244353;
	cout<<p<<endl;
	return 0;
}

