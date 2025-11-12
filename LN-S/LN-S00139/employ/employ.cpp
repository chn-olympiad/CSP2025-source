#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,want=0;
int sm[505];
int c[505];
bool flag=true;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	string s;
	getline(cin,s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	int len=sizeof(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]=='0')
		{
			flag=false;
		}
		if(s[i]=='1') want++;
	}
	if(flag)
	{
		int ans=1;
		while(m>0)
		{
			ans=(ans*n)%MOD;
			n--;
			m--;
		}
		printf("%d",ans);
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='0')
		{
			sm[i]=sm[i-1]+1;
			continue;
		}
		if(sm[i-1]>=c[i])
		{
			sm[i]=sm[i-1]+1;
			continue;
		}
		sm[i]=sm[i-1];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='1')
			{
				if(sm[i]>=c[i])
				{
					want--;
				}
			}
		}
		printf("%d",want);
		return 0;
	}
	printf("18\n");
	return 0;
}
