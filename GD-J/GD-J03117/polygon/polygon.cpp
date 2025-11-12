#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int d[5010],a[5010];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,t=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];		
	sort(a+1,a+n+1);
	d[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=5001;j>a[i];j--)
			if(j>a[i])
				(t+=d[j])%=998244353;
		for(int j=5001;j>=0;j--)
			(d[min(j+a[i],5001ll)]+=d[j])%=998244353;
	}
	cout<<t;
	return 0;
}

