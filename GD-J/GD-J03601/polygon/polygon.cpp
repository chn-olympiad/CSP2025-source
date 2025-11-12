#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5009];
int n,ans=0;
void dfs(int k,ll l,int y)
{
	y++;
	if(k>n)
	return ;
	for(int i=k;i<=n;i++)
	{
		l=l+a[i];
		if(l>a[i]*2 && y>=3)
		{
			ans++;
		}
		dfs(i+1,l,y);
		l=l-a[i];
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans;
	
	
	
	
	fclose(stdin);fclose(stdout);
	return 0;
}
