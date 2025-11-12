#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
int n,m,a[N],c[N];
char s[N];
ll mod=998244353,ans=0,jc[505],f[505][505];
int vis[N];
void dfs(int step,int cnt,int anss)
{
//	cout << step << " " <<cnt << " " << anss <<" " << endl;
	if(step==n+1)
	{
		if(anss>=m) ans++,ans%=mod;
//		cout << ans << 1234 << " " << endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
//		cout << i  << endl;
		vis[i]=1;
		int o1=0,o2=0;
		if(c[i]<=cnt || a[step]==0) o1=1;
		else o2=1;
		dfs(step+1,cnt+o1,anss+o2);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i];
		a[i]=(s[i]=='1');
		if(!a[i]) flag=1;
	}
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	jc[0]=1;
	for(int i=1;i<=n;i++)
	{
		jc[i]=jc[i-1]*i%mod;
//		cout << jc[i] << endl;
	}
	if(!flag)
	{
		f[0][0]=1;
		for(int i=1;i<=n;i++)//题 
		{
			for(int j=1;j<=n;j++)//人 
			{
				for(int k=1;k<=n;k++)//0个数 
				{
					
				}
			}
		}
		return 0;
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
} 
//Ren5Jie4Di4Ling5%
