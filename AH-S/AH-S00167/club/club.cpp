#include<bits/stdc++.h>
using namespace std;
struct node{
	int a2,b2,c2;
	bool cnt;
}a[100005];
int n,maxn;
void dfs(int step,int k,int a1,int b1,int c1)
{
	if(step==n+1)
	{
		maxn=max(maxn,k);
		return;
	}
	if(a[step].cnt==0)
	{
		if(a1<n/2)
		{
			a[step].cnt=1;
			dfs(step+1,k+a[step].a2,a1+1,b1,c1);
			a[step].cnt=0;
		}
		if(b1<n/2)
		{
			a[step].cnt=1;
			dfs(step+1,k+a[step].b2,a1,b1+1,c1);
			a[step].cnt=0;
		}
		if(c1<n/2)
		{
			a[step].cnt=1;
			dfs(step+1,k+a[step].c2,a1,b1,c1+1);
			a[step].cnt=0;
		}
	}
	else
		dfs(step+1,k,a1,b1,c1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		maxn=INT_MIN;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a2>>a[i].b2>>a[i].c2;
			a[i].cnt=0;
		}
		dfs(0,0,0,0,0);
		cout<<maxn<<endl;
	}
	return 0;
}
