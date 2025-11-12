#include<iostream>
#include<cstdio>
using namespace std;
long long a[5005],maxn=0,cnt,ans,t,n;
void f(long long b,int c)
{
	int x=1;
	for(int i = 1;i<=c;i++)
	{
		x*=b+1-i;
	}
	for(int i = 2;i<=c;i++)
	{
		x/=i;
	}
	ans+=x;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n<3)
		cout << 0;
	else if(n==3)
	{
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i];
			cnt+=a[i];
			if(a[i]>maxn)
				maxn=a[i];
			if(a[i]==1)
				t++;
		}
		if(cnt>2*maxn)
			ans++;
	}
	else
	{
		for(int i = 3;i<=t;i++)
		{
			f(n,i);
			ans%=998224353;
		}
	}
	cout << ans;
	return 0;
}
