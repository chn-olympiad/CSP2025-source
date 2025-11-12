#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+10;
int a[N];
int b[N];
bool flag[N];
int p[N];
int ans=0;
void dfs(int l)
{
	if(l>n)
	{
		int ko=0;
		for(int i=1;i<=n;i++)
		{
			if(ko>=b[p[i]]||a[i]==0)ko++;
		}
		if(n-ko>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i])continue;
		flag[i]=1;
		p[l]=i;
		dfs(l+1);
		p[l]=0;
		flag[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char t;
		cin>>t;
		a[i]=t-'0';
	}
	for(int i=1;i<=n;i++)cin>>b[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
