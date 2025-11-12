#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b[1000005],c[1000005],ans;
string s;
void dfs(int x,int y)
{
	for(int i=x;i<=n;i++)
	{
		if(!b[i]&&a[i]!=0)
		{
			b[i]=1;
			c[y]=a[i];
			if(i==m)
			{
				ans++;
			}
			else
			{
				dfs(i,y+1);
			}
			b[i]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,1);
	cout<<ans;
	return 0;
} 

