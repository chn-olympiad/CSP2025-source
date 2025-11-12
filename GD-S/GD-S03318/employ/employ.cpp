#include<bits/stdc++.h>
using namespace std;
const int MOD=85959736; 
int n,m,flag=1,ls,sum=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	getline(cin,s);
	for(int i=0;i<=n-1;i++)
	{
		if(s[i]!='1')
		{
			flag=0;
		}
	}
	if(flag)
	{
		for(register int i=m;i<=n;i++)
		{
			ls=n;
			for(register int j=1;j<=i;j++)
			{
				sum*=ls;
				sum%=MOD;
				ls--;
			}
		}
	}
	printf("%d",sum);
	return 0;
}
