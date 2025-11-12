#include<bits/stdc++.h>
using namespace std;
int book[100002];
int maxn=INT_MIN;
int maxnn=INT_MIN;
int a[10002];
int sum,ans,flag;
int n;
void dfs(int x)
{
	if(sum>=maxn*2)
	{
		ans++;
		ans=ans%998244353;
	}
	for(int i=x;i<=n;i++)
	{
		if(!book[a[i]])
		{
			book[a[i]]=1;
			maxn=max(maxn,a[i]);
			sum+=a[i];
			dfs(i);
			sum-=a[i];
			if(flag==i)
				maxn=maxnn;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		memset(book,0,sizeof(book));
		sum=0;
		maxn=INT_MIN;
		maxnn=INT_MIN;
		dfs(i);
	}
	cout<<ans%998244353;
	return 0;
}
