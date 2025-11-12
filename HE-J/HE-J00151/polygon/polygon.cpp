#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long ans,h=1;
int a[105];

void dfs(int sum,int maxh,int cur,int s)
{
	if(s >= 3 && sum > maxh*2)
	{
		ans++;
		return;
	}
	
	if(cur == n+1) return;
	
	dfs(sum+a[cur],max(maxh,a[cur]),cur+1,s+1);
	dfs(sum,maxh,cur+1,s);
}

int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			h *= cnt;
			cnt=1;
		}
		else cnt++;
	}
	
	dfs(0,0,1,0);
	
	cout<<(ans/h) % 998244353;
	return 0;
}
