#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int book[5005];
int maxn;
long long sum,cnt,t;
void find(int x,int mt,int step)
{
	book[x]==1;
	t=maxn;
	maxn=max(maxn,a[x]);
	sum+=a[x];
	if(step==mt)
	{
		if(sum>maxn*2) cnt++;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(book[i]==0)
		{
			find(i,mt,step+1);
		}
	}
	maxn=t;
	sum-=a[x];
}
			
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			find(j,i,1);
		}
	}
	cout<<cnt%998%244%353;
	return 0;
}

