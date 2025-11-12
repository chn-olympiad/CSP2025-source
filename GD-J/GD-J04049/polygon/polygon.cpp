#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0;
int a[5010];
int b[5010];
int vis[5010];
int index1[5010];
int dfs(int no,int sum)
{
	if(no>n)
	{
		if(sum>2*a[b[no-1]])
		{
			cnt++; 
		}
		return 0;
	}
	else if(no>3)
	{
		if(sum>2*a[b[no-1]])
		{
			cnt++; 
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0&&index1[i]>=b[no-1])
		{
			vis[i]=1;
			b[no]=index1[i];
			dfs(no+1,sum+a[index1[i]]);
			b[no]=0;
			vis[i]=0;		
		}
	}
	return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		index1[i]=i;
	}
	sort(a+1,a+1+n);
	dfs(1,0);
	cout<<cnt%998244353;
	return 0;
}
