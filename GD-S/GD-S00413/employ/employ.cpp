#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,sum[505],l;
bool b[505];
long long ans=1;
string s;
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int b=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1') b++;
	}
	if(b==n)
	{
		ans=1;
		for(int i=2;i<=n;i++) ans=(ans*i)%mod;
		printf("%lld",ans);
		return 0;
	}
	if(b<m)
	{
		printf("0");
		return 0;
	}
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1];
		if(s[i]=='0') sum[i]++;
	}
	for(int i=1;i<=m;i++)
	{
		l=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]>sum[i]) l++;
		}
		if(l==0) l=1;
		while(sum[i+1]==sum[i]&&i<m&&l>0)
		{
			ans*=l;
			l--;
			i++;
		}
	}
	for(int i=n-m+1;i>0;i--) ans*=i; 
	printf("%lld",ans);
	return 0;
}
