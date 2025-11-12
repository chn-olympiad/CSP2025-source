#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100905;
int T,ans,n,f1,f2,f3;
struct node
{
	int c1,c2,c3;
}a[N];
bool cmp1(node a,node b)
{
	return a.c1>b.c1;
}
bool cmp2(node a,node b)
{
	return a.c2>b.c2;
}
bool cmp3(node a,node b)
{
	return a.c3>b.c3;
}
void dfs1(int p,int cnt2,int cnt3,int sum)
{
	if (p==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	
	if (cnt2==n/2) 
	{
		dfs1(p+1,cnt2,cnt3+1,sum+a[p].c3);
	}
	else if (cnt3==n/2)
	{
		dfs1(p+1,cnt2+1,cnt3,sum+a[p].c2);
	}
	else 
	{
		dfs1(p+1,cnt2+1,cnt3,sum+a[p].c2);
		dfs1(p+1,cnt2,cnt3+1,sum+a[p].c3);
	}
	return;
}
void dfs2(int p,int cnt1,int cnt3,int sum)
{
	if (p==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if (cnt1==n/2) 
	{
		dfs2(p+1,cnt1,cnt3+1,sum+a[p].c2);
	}
	else if (cnt3==n/2)
	{
		dfs2(p+1,cnt1+1,cnt3,sum+a[p].c1);
	}
	else 
	{
		dfs2(p+1,cnt1+1,cnt3,sum+a[p].c1);
		dfs2(p+1,cnt1,cnt3+1,sum+a[p].c2);
	}
}
void dfs3(int p,int cnt1,int cnt2,int sum)
{
	if (p==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if (cnt1==n/2) 
	{
		dfs3(p+1,cnt1,cnt2+1,sum+a[p].c2);
	}
	else if (cnt2==n/2)
	{
		dfs3(p+1,cnt1+1,cnt2,sum+a[p].c1);
	}
	else 
	{
		dfs3(p+1,cnt1+1,cnt2,sum+a[p].c1);
		dfs3(p+1,cnt1,cnt2+1,sum+a[p].c2);
	}
	return;
}
void dfs4(int p,int cnt1,int cnt2,int cnt3,int sum)
{
	if ((cnt1>n/2)||(cnt2>n/2)||(cnt3>n/2)) return;
	if (p==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	dfs4(p+1,cnt1,cnt2+1,cnt3,sum+a[p].c2);
	dfs4(p+1,cnt1+1,cnt2,cnt3,sum+a[p].c1);
	dfs4(p+1,cnt1,cnt2,cnt3+1,sum+a[p].c3);
	return;
}
void solve1()
{
	if (f3==f2)
	{
		sort(a+1,a+n+1,cmp1);
		for (int i=1;i<=n/2;i++)
		{
			ans+=a[i].c1;
		}
		cout << ans << "\n";
	}
	else if(f3==f1)
	{
		sort(a+1,a+n+1,cmp2);
		for (int i=1;i<=n/2;i++)
		{
			ans+=a[i].c2;
		}
		cout << ans << "\n";
	}
	else 
	{
		sort(a+1,a+n+1,cmp3);
		for (int i=1;i<=n/2;i++)
		{
			ans+=a[i].c3;
		}
		cout << ans << "\n";
	}
}
void solve2()
{
	if (f1==0)
	{
		dfs1(1,0,0,0);
		cout << ans << "\n";
	}
	else if (f2==0)
	{
		dfs2(1,0,0,0);
		cout << ans << "\n";
	}
	else 
	{
		dfs3(1,0,0,0);
		cout << ans << "\n";
	}
}
void solve3()
{
	dfs4(1,0,0,0,0);
	cout << ans << "\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n;
		ans=f1=f2=f3=0;
		for (int i=1;i<=n;i++)
		{
			cin >> a[i].c1 >> a[i].c2 >> a[i].c3;
			f1+=a[i].c1;
			f2+=a[i].c2;
			f3+=a[i].c3;
		}
		if (f1==f2&&f3==f2&&f1==0)
		{
			cout << 0 << "\n";
		}
		else if ((f1==f2&&f1==0)||(f1==f3&&f1==0)||(f2==f3&&f2==0))
		{
			solve1();
		}
		else if((f1==0)||(f2==0)||(f3==0))
		{
			solve2();
		}
		else if (f1!=0&&f2!=0&&f3!=0) solve3();
	}
	return 0;
}
