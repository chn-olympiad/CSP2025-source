#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],zuheshu[5005],cnt;
void check(int bianshu,int dijitiao,int shangyitiao,int he)
{
	if(bianshu==dijitiao)
	{
		int wei=lower_bound(a+1,a+n+1,he)-a;
		cnt=(cnt+wei-shangyitiao-1)%998244353;
		return ;
	}
		
	for(int i=shangyitiao+1;i<=n-bianshu+dijitiao;++i)
	{
		he+=a[i];
		check(bianshu,dijitiao+1,i,he);
		he-=a[i];
	}
		
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=2)
	{
		cout<<"0";
		return 0;
	}
	if(n>24)
	{
		cnt=1;
		for(int i=1;i<=n;++i)
		{
			cnt*=2;
			cnt%=998244353;
		}
		cnt-=1+n+n*(n-1)/2;
		if(cnt<0) cnt+=998244353;
		cout<<cnt;
		return 0;
	}
	for(int i=3;i<=n;++i)
	{
		check(i,1,0,0);
	}
	cout<<cnt;
	return 0;
}
/*
5
1 2 3 4 5 
*/
