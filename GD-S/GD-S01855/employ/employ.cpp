#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ansn;
char c;
int a[505];
int pa[505];
int tong[505];
int zuhe(int on,int down)
{
	int ans=1;
	for(int i=on-down+1;i<=on;i++)
	{
		ans*=i;
		ans%=998244353;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='0')
		a[i]++;
		a[i]+=a[i-1];//pai>ai;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>pa[i];
	}
	if(n-a[n]>m)
	{
		printf("0");
		return 0;
	}
	else if(n==m)
	{
		sort(pa+1,pa+n);
//		cout<<pa[1];
		for(int i=1;i<=n;i++)
		{
			tong[pa[i]]++;
		}
		long long ansn=1;
		int p=0;
		for(int i=1;i<=n;i++)
		{
			if(tong[i]!=0)
			{
				p+=tong[i];
				ansn*=zuhe(i-p+tong[i],tong[i]);
				ansn%=998244353;
			}
		}
		printf("%lld",ansn);
		return 0;
	}
	else
	{
		printf("1");
		return 0;
	}
}
