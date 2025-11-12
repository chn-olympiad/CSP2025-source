#include<iostream>
#include<algorithm>
using namespace std;
int a[5001];

long long ans=0,n,m;

void f(int p,int sum,int last)
{
	if(p > m)
	{
		if(sum > a[last]*2)
			ans++;
		return;
	}
	for(int i=last+1;i<=n-m+p;i++)
		f(p+1,sum+a[i],i);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		m=i;
		f(1,0,0);
		ans%=998244353;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
