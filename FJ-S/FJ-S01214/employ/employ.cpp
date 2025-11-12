#include<bits/stdc++.h>
#define ll long long
#define N 510
using namespace std;
bool vis[N];
char c[N];
int n,k,now,qwq,ans,mod=998244353;
int a[N];
ll jiecheng[N];
void dfs(int x)
{
	if(now>=k)
	{
		ans=(ans+jiecheng[n-x+1])%mod;
		return; 
	}
	if(x==n+1)
		return;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			bool tmp=0;
			vis[i]=1;
			if(c[x]=='1'&&qwq<a[i])
			{
				now++;
				tmp=1;
			}
			else
				qwq++;
			dfs(x+1);
			if(tmp)
				now--;
			else
				qwq--;
			vis[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jiecheng[0]=1;
	for(int i=1;i<=500;i++)
		jiecheng[i]=jiecheng[i-1]*i%mod;
	cin>>n>>k>>c+1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
