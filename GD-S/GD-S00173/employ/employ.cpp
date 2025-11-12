#include<bits/stdc++.h>
using namespace std;
int n,m;
bool ca[21];
int c[21],p[21]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
bool cmp()
{
	int cnt=0,now=0;
	for(int i=1;i<=n;i++)
	{
		while(now>=c[p[i]]&&i<=n)now++,i++;
		if(ca[i])cnt++;
		else now++;
		if(cnt==m)return 1;
	}
	return 0;
}
long long jc()
{
	if(n==500)return 694848220;
	else if(n>=450)
	{
		long long s=123951161;
		for(int i=451;i<=n;i++)s=(s*i)%998244353;
		return s;
	}
	else if(n>=400)
	{
		long long s=728580680;
		for(int i=401;i<=n;i++)s=(s*i)%998244353;
		return s;
	}
	else if(n>=350)
	{
		long long s=706902646;
		for(int i=351;i<=n;i++)s=(s*i)%998244353;
		return s;
	}
	else if(n>=300)
	{
		long long s=310896195;
		for(int i=301;i<=n;i++)s=(s*i)%998244353;
		return s;
	}
	else if(n>=250)
	{
		long long s=425577253;
		for(int i=251;i<=n;i++)s=(s*i)%998244353;
		return s;
	}
	else if(n>=200)
	{
		long long s=245648024;
		for(int i=201;i<=n;i++)s=(s*i)%998244353;
		return s;
	}
	else if(n>=150)
	{
		long long s=723725482;
		for(int i=151;i<=n;i++)s=(s*i)%998244353;
		return s;
	}
	else if(n>=100)
	{
		long long s=35305197;
		for(int i=101;i<=n;i++)s=(s*i)%998244353;
		return s;
	}
	else if(n>=50)
	{
		long long s=700438304;
		for(int i=51;i<=n;i++)s=(s*i)%998244353;
		return s;
	}
	else
	{
		long long s=1;
		for(int i=2;i<=n;i++)s=(s*i)%998244353;
		return s;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool pd=true;
	for(int i=1,a;i<=n;i++)
	{
		scanf("%1d",&a);
		ca[i]=(a==1);
		pd=(pd&&ca[i]);
	}
	if(pd)
	{
		printf("%lld",jc());
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	long long ans=0;
	do
	{
		ans+=cmp();
	}while(next_permutation(p+1,p+1+n));
	printf("%lld",ans);
	return 0;
}
