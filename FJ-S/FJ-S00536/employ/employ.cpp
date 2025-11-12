#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,m;
char ch[10005];
int c[10005];
long long ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>ch;
	int len=strlen(ch);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0||ch[i-1]=='0')
			{
				printf("0\n");
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans*(i%MOD))%MOD;
		}
		printf("%lld\n",ans);
		return 0;
	}
	/*bool flag=true;
	for(int i=0;i<=n-1;i++)
	{
		if(ch[i]!='1')flag=false;
	}
	if(flag)
	{
		int op=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0){op++;}
		}
		if(op>(n-m)){printf("0\n");return 0;}
	} */ 
}
