#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long ans = 0;
int n, m;
string s;
int a[1005], c[1005], bot[1005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	bool flag = true;
	s = ' ' + s;
	for(int i = 1; i <= n; i++)
	{
		a[i] = s[i]-'0';
		if(a[i]==0)
		{
			flag = false;
		}
	}
	if(flag == true)
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> c[i];
			bot[c[i]]++;
			if(c[i]==0) 
			{
				cnt++;
			}
		}
		sort(c+1,c+1+n); 
		if(n-cnt<m)printf("0\n");
		else{
			ans = 1;
			long long mul = 1;
			for(int i = 1; i <= n-cnt; i++)
			 mul = mul * i % mod;
			ans = mul;
			//for(int i = )
			printf("%lld\n",ans);
		}
	}else if(m==1)
	{
		int maxn = 0, tag = 0, cnt = 0;
		flag = true;
		for(int i = 1; i <= n; i++)
		{
			if(a[i]==0) tag++;
			else{
				break;
			}
		}
		if(tag==n)
		{
			printf("0\n");
			return 0;
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> c[i];
			bot[c[i]]++;
			maxn = max(maxn,c[i]);
		}
		sort(c+1,c+1+n);
		if(maxn > tag){
			for(int i = n; i >= 1; i--)
			{
				if(c[i] > tag) cnt++;
			}
			ans = cnt % mod;
			int t = n-1;
			for(int i = 1; i < n; i++)
				ans = (ans * (t-i+1)) % mod;
			printf("%lld\n",ans%mod); 
		}else{
			printf("0\n");
		}
	}else if(m==n)
	{
		for(int i = 1; i <= n; i++)
		{
			cin >> c[i];
			if(c[i]==0||a[i]==0)
			{
				printf("0\n");	
				return 0;	
			}
		}
		sort(c+1,c+1+n);
		int t = n, cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i]==1)ans = (ans * (t-i+1)) % mod;
			else if(a[i]==0) ans = (ans * t) % mod, t -= bot[++cnt];	
		}	
		printf("%lld",ans);
	}
}
