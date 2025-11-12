#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1e5+5;
int T,n;
long long ans=0,a[N][4],cop[N];
void Dfs(int dep,int t1,int t2,int t3,long long res)
{
	if(dep==n+1)
	{
		ans=max(ans,res);
		return;
	}
	if(t1+1<=n/2) Dfs(dep+1,t1+1,t2,t3,res+1ll*a[dep][1]);
	if(t2+1<=n/2) Dfs(dep+1,t1,t2+1,t3,res+1ll*a[dep][2]);
	if(t3+1<=n/2) Dfs(dep+1,t1,t2,t3+1,res+1ll*a[dep][3]);
}
void solve1()
{
	Dfs(1,0,0,0,0);
	cout<<ans<<'\n';
}
void solve2()
{
	for(int i=1;i<=n;i++)
		cop[i]=a[i][1];
	sort(cop+1,cop+n+1);
	for(int i=n;i>(n/2);i--)
		ans+=1ll*cop[i];
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	IOS;
	cin>>T;
	while(T--)
	{
		ans=0;
		bool spea=true;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]>0||a[i][3]>0)
				spea=false;
		}
		if(n<=10)
			solve1();
		else if(spea)
			solve2();
	}
	return 0;
}