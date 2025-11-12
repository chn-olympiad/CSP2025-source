#include <bits/stdc++.h>
using namespace std;
int a[5050];
long long b[5050];
int n;
long long zuida,ans;
void dfs(int x)
{
	if(x>n)return ;
	for(int l=1,r=x;r<=n;l++,r++)
	{
		zuida=a[r];
		if(b[r]-b[l-1]>zuida*2)
		{
			//cout<<l<<r<<" ";
			ans++;
		}
	}
	dfs(x+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=b[i-1]+a[i];
	sort(a+1,a+n+1);
	dfs(3);
	cout<<ans;
	return 0;
}


