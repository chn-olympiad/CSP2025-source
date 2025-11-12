#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,maxn;
bool vis[5000];
int a[5000];
map<int,int>mp;
vector<int> ve;
void dfs(int num,int sum,int mmaxn,int fontt)
{
	if(num>=3) if(sum>mmaxn*2) cnt++;
	if(fontt==n) return;
	for(int i=fontt;i<=n;i++) if(!vis[i])
	{
		vis[i]=true;
		dfs(num+1,sum+a[i],max(mmaxn,a[i]),i);
		vis[i]=false;
	}
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mp[a[i]]++;
		if(mp[a[i]]==1) ve.push_back(a[i]);
		maxn=max(maxn,a[i]);
	}
	sort(ve.begin(),ve.end());
	//1~3
	if(n<=3)
	{
		if(n==3) 
		{
			if(a[1]+a[2]+a[3]>maxn*2) printf("1");
			else printf("0");
		}
		else printf("0");
		return 0;
	}
	//4~10
	if(n<=20)
	{
		dfs(0,0,0,1);
		printf("%lld ",cnt);
		return 0;
	}
	//15~20
//	if(maxn==1)
//	{
//		for(int i=n;i>=3;i--)
//		{
//			
//		}
//	}
	//else
	return 0;
}
//998244353