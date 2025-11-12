#include<iostream>
#include<algorithm>
using namespace std;
int n;
int ans=0;
int a[5005];
void dfs(int start,int end,int need)
	{
		if(need<0)
		{
			ans++;
		}
		if(start>end)
		{
			return;
		}
		dfs(start+1,end,need-a[start]);
		dfs(start+1,end,need);	
	}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a,a+n+1);
	for(int i=3;i<=n;i++)
	{
		dfs(1,i-1,a[i]);
	}
	cout<<ans;
	return 0;
}
