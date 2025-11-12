#include<bits/stdc++.h>
using namespace std;
long long a[500010],pre[500010],cnt;
bool vis[500010];
long long n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//输入及前缀和
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	//统计
	vis[1]=1;
	for(int i=1;i<=n;i++)
	{
		int s=k^pre[i];
		if(vis[s] || a[i]==k)//如果已经有或相等
		{
			cnt++;
			memset(vis,0,sizeof(vis));
		}
		vis[pre[i]]=1;//标记
	}
	cout<<cnt;
	return 0;
}