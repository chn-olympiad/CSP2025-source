#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+7;
int T;
ll a[N][5],ans,pf[N],maxn;
int n,mk[5],mid;
ll xqmbz;
ll GG=1e7+666;
pair<ll,int>s[5];
bool cmp(pair<ll,int>x,pair<ll,int>y)
{
	return x.first>y.first;
}
void dfs(int x,ll sum)
{
	if(sum+(n-x+1)*maxn<=ans) return;
	xqmbz++;
	if(xqmbz>=GG)
	{
		return;
	}
	if(x==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		s[i]=make_pair(a[x][i],i);
	}
	sort(s+1,s+4,cmp);
	int k1=s[1].second,k2=s[2].second,k3=s[3].second;
	if(mk[k1]<mid)
	{
		mk[k1]++;
		dfs(x+1,sum+a[x][k1]);
		mk[k1]--;
	}
	if(mk[k2]<mid)
	{
		mk[k2]++;
		dfs(x+1,sum+a[x][k2]);
		mk[k2]--;
	}
	if(mk[k3]<mid)
	{
		mk[k3]++;
		dfs(x+1,sum+a[x][k3]);
		mk[k3]--;
	}
}
void init()
{
	xqmbz=0;
	memset(mk,0,sizeof mk);
	mid=n/2;
	ans=0;
	memset(pf,0,sizeof pf);
	maxn=0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		init();
		int flag1=0,flag2=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				maxn=max(maxn,a[i][j]);
			}
			if(a[i][1]!=0||a[i][3]!=0)
			{
				flag1=1;
			}
			if(a[i][3]!=0)
			{
				flag2=0;
			}
		}
		if(flag1==0)
		{
			for(int i=1;i<=n;i++)
			{
				pf[i]=a[i][2];
			}
			sort(pf+1,pf+1+n);
			for(int i=n;i>=mid+1;i--)
			{
				ans+=pf[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
