#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510,mod = 998244353;
int n,m,a[N],b[N],v[N],ans,sum,l,o;
string s;
void dfs(int x)
{
	if(x > n)
	{
		int S = 0;
		for(int i = 1;i <= n;i++)
			if(S >= a[b[i]]) S++;
			else if(s[i] == '0') S++;
		if(n-S >= m) ans++;
		return;
	}
	for(int i = 1;i <= n;i++)
		if(!v[i]) b[x] = i,v[i] = 1,dfs(x+1),v[i] = 0;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> s; s = ' '+s;
	for(int i = 1;i <= n;i++) 
		if(s[i] == '1') sum++;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(sum < m)//一定不可能 
	{
		cout<<0;
		return 0;
	}
	if(m == n)
	{
		for(int i = 1;i <= n;i++) ans = ans*i%mod;
		cout<<ans;
		return 0;
	}
	if(n <= 10)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m == 1)
	{
		sort(a+1,a+1+n);
		for(int i = 1;i <= n;i++)
			if(s[i] == '1')
				for(int j = 1;j <= n;j++)
					if(i-1 < a[j])
					{
						l = 1; sum = 1; o = 0;
						for(int z = 1;z <= n;z++)
							if(s[z] == '1')
							{
								if(z < i)
								{
									while(l <= n && (l == j || a[l] <= z-1)) o += (l != j),l++;
									sum = sum*o%mod,o--;
								}
								else if(i < z)
								{
									while(l && (l == j || a[l] > z-2)) o -= (l != j),l--;
									while(l <= n && (l == j || a[l] <= z-2)) o += (l != j),l++;
									sum = sum*o%mod,o--;
								}
							}
						while(l <= n) o += (l != j),l++;
						while(o) sum = sum*o%mod,o--;//其它随便放 
						ans = (ans+sum)%mod;
					}
		cout<<ans;
		return 0;
	} ans = 1;
	for(int i = 1;i <= sum;i++) ans = ans*i%mod;
	cout<<ans;
	return 0;
}
/*
当n = m，每个人都必须成功
那么首先所有s_i=1才行
那么一定可以了 
m=1，那么要恰好有一个s_i=1的位置可以
枚举这里i，那么前面所有s_j=1的位置需要j-1>=c_x的去
后面的就是j-2>=c_x的去，然后这里需要满足i-1<c_x
考虑暴力枚举i和选的x，然后dp求即可 
*/
