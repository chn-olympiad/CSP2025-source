#include<bits/stdc++.h>
using namespace std;
long long a[5002],n,cnt;
void dfs(long long tot,long long maxn,int sn,int now,bool jud)
{
	if(sn>=3&&tot>maxn*2&&jud==1)
	{
		cnt++;
	}
	if(now>n) return;
	int maxx=max(maxn,a[now]);
	dfs(tot+a[now],maxx,sn+1,now+1,1);
	dfs(tot,maxn,sn,now+1,0);
}
void spe(int sn,int now,bool jud)
{
	if(sn>=3&&jud==1)
	{
		cnt++;
	}
	if(now>n) return;
	spe(sn+1,now+1,1);
	spe(sn,now+1,0);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long mm=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mm=max(mm,a[i]);
	}
	if(mm==1)
	{
		spe(0,1,1);
	}
	else 
	{
		dfs(0,0,0,1,1);
	}
	cnt=cnt%998244353;
	cout<<cnt;
	return 0;
}
