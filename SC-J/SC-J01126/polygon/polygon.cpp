#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans;
bool cmp(int a,int b)
{
	return a>b;
}
void p(int x,int i,int cnt,int sum,int maxn)
{
	if (cnt==x)
	{
		if (sum>maxn*2)
			ans=(ans+1)%mod;
		return ;
	}
	for (int j=i+1;j<=n;j++)
	{
		sum+=a[j];
		p(x,j,cnt++,sum,maxn);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n,cmp);
	for (int i=3;i<=n;i++)
		for (int j=1;j<=n-i+1;j++)
			p(i,j,1,a[j],a[j]);
	cout<<ans;
	return 0;
}
