#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int a[50][50];
int n;
int l[100010];
int b[555];
unordered_map<string,bool> vis;
int ans;
void dfs(int now,int num,int tot,int ma,string s)
{
	if(now > n + 1) return;
	if(num >= 3)
	{
		if(tot > ma * 2 && (!vis[s]))
		{
			vis[s] = 1;
			ans ++ ;	
		} 
	}
	dfs(now + 1,num + 1,tot + l[now],l[now],s + char(now + '0'));
	dfs(now + 1,num,tot,ma,s);	
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1;i <= n;i ++ ) cin >> l[i];
	sort(l + 1,l + n + 1);
//	if(l[n] == 1)
//	{
//		int k = 1;
//		for(int i = 1;i <= n;i ++ )
//		{
//			k *= i;
//			b[i] = k;
////			cout << b[i] << " " ;
//		}
//		for(int i = 3;i < n;i ++ )
//		{
//			int aa = b[n] / b[i];
//			aa = aa / b[n - i];
//			aa %= mod;
//			ans += aa;
//			ans %= mod;
//		}
//		ans ++ ;
//	}
//	else
//	{
		dfs(1,0,0,0,"");
//	}
	
	cout << ans%mod;
	return 0;
}
