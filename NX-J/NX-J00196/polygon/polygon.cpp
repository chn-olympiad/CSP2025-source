#include<bits/stdc++.h>
#define N 100005
#define M 100005
#define int long long
using namespace std;
int n,a[N],s[N],ans;
priority_queue<int>q;
queue<int>qq;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3)
	{
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	if(a[n]==1)
	{
		for(int i=3;i<=n;i++)
		{
			int x=min(i,n-i);
			int sum=1,sum2=1;
			for(int j=1;j<=x;j++)
			{
				sum*=j;
			}
			for(int j=n;j>=n-x+1;j--)
			{
				sum2*=j;
				if(sum2%sum==0)sum2/=sum;
			}
			ans+=sum2;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	q.push(a[1]);
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			q.push(s[i-1]-s[j-1]);
		}
		while(q.top()>a[i])
		{
			ans++;
			qq.push(q.top());
			q.pop();
		}
		while(qq.size())
		{
			q.push(qq.front());
			qq.pop();
		}
	}
	cout<<ans;
	return 0;	
}
/*
ji xu zheng huo
(hua shuo geany shen mi de zhu shi xi tong za hui shi a wei!
//freopen//freopen//freopen//freopen//freopen//freopen
*/
