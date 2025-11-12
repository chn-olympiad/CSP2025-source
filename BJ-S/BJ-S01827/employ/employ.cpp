#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,c[N],cnt[N],a[N],ans;
char s[N];
bool vis[N];
void dfs(int p)
{
	if(p>n)
	{
		int sum=0,an=0;
		for(int i=1;i<=n;i++)
		{
			if(sum<c[a[i]]&&s[i-1]=='1')
			{
				an++;
			}
			else sum++;
		}
		if(an>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			a[p]=i;
			dfs(p+1);
			vis[i]=false;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
