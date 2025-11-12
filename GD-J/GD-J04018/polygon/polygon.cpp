#include <bits/stdc++.h>
#define int long long
#define loop(a,b) for (int a = 1 ; a <= b ; ++a)
using namespace std;
int a[5005];
const int mod = 998244353;
int n,ans;
void dfs(int x,int sum,int lst,int cnt)
{
	if (x==n+1)
	{
		if (cnt<3) return;
		if (sum>a[lst]*2) ans++;
		ans=ans%mod;
		return;
	}
	dfs(x+1,sum+a[x],x,cnt+1);
	dfs(x+1,sum,lst,cnt);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int type=0;
	cin >> n;
	if (n<3)
	{
		cout << 0 << endl;
		return 0;
	}
	loop(i,n)
	{
		cin >> a[i];
		if (a[i]>1&&type==0) type=1;
		if (a[i]>10&&type==1) type=2;
		if (a[i]>100&&type==2) type=3;
	}
	/*
	type:0 ai=1
	type:1 ai<=10
	type:2 ai<=100 
	*/
	if (type==1&&n<=3)
	{
		if (a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
		{
			cout << 1 << endl;
			return 0;
		} else cout << 0 << endl;
		return 0;
	}
	if (type==0)
	{
		ans=1;
		loop(i,n) ans=(ans*2)%mod;
		ans+=mod;
		ans-=n;
		ans-=((n-1)*n)/2+1;
		ans=ans%mod;
		cout << ans << endl;
		return 0;
	}
	if (type==2&&n<=20)
	{
		sort(a+1,a+n+1);
		dfs(1,0,0,0);
		ans=ans%mod;
		cout << ans << endl;
		return 0;
	}
	cout << 0 << endl;
	return 0;
}
