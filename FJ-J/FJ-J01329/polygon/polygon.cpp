#include<bits/stdc++.h>
using namespace std;
int n,a[5001],cnt,b;
bool used[5001];
int dfs(int k,int sum,int max1)
{
	for(int i=1;i<=n;i++)
	{
		if(!used[i])
		{
			sum+=a[i];
			used[i]=true;
			if(a[i]>max1)
			max1=max(max1,a[i]);
		}
		if(max1*2>sum)
		cnt++;
		else dfs(k+1,sum-a[i],max1);
		sum-=a[i];
		used[i]=false;
		max1=0;
	}
	return cnt;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	cin>>a[i];
	int max1=0,sum=0;
	if(n==3)
	{
		for(int i=1;i<=3;i++)
		{
			max1=max(a[i],max1);
			sum+=a[i];
		}
		if(sum>max1*2)
		printf("%d",1);
		else
		printf("%d",0);
		return 0;
	}
	cout<<dfs(1,0,0);
	return 0;
}
