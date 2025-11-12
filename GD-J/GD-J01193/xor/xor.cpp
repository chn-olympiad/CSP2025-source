#include <bits/stdc++.h>
using namespace std;
//long long
const int N = 5*1e5+10;
long long a[N],q[N],f[N];
signed main()
{
	//这题至少要用nlogn,咋做啊 
	//zph的特色标记
	//ccf orz
	//noi orz
	//cspj orz
	//luogu orz
	//tuling orz
	//noip orz
	//csps orz
	//teachers orz
	//machine orz
	//all things orz
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	//球球ccf别爆零，爹！ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0); 
	long long n,k;
	cin >> n >> k;
	
	for(long long i = 1;i<=n;i++)cin >> a[i];
	
	if(k == 0)
	{
		long long cnt = 0;
		for(long long i = 1;i<=n;i++)
		{
			if(a[i] == 0)cnt++;
		}
		cout << cnt;
		return 0;
	}
	
	if(k == 1)
	{
		long long cnt = 0;
		for(long long i = 1;i<=n;i++)
		{
			if(a[i] == 1)cnt++;
		}
		cout << cnt;
		return 0;
	}
	
	
	//o(n^2)
	
	for(long long i = 1;i<=n;i++)
	{
		long long t = q[i-1] ^ a[i];
		q[i] = t;
	}
	
	for(long long i = 1;i<=n;i++)
	{
		for(long long j = 1;j<=i;j++)
		{
			long long t = q[j-1] ^ q[i];
			if(t == k)
			{
				f[i] = max(f[j-1] + 1,f[i]);
			}
			else f[i] = max(f[j-1],f[i]);
			//1~i中最多有多少个区间数量
		}
	}
	cout << f[n];
	
	return 0;
} 
// xor前缀和
//        000 
// 5 :101 101 5
// 7 :111 010 2
// 3 :011 001 1
// 2 :010 011 3

/*

#include <bits/stdc++.h>
using namespace std;
//long long
const int N = 5*1e5+10;
long long a[N],q[N],f[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	
	for(long long i = 1;i<=n;i++)cin >> a[i];
	
	if(k == 0)
	{
		long long cnt = 0;
		for(long long i = 1;i<=n;i++)
		{
			if(a[i] == 0)cnt++;
		}
		cout << cnt;
		return 0;
	}
	
	if(k == 1)
	{
		long long cnt = 0;
		for(long long i = 1;i<=n;i++)
		{
			if(a[i] == 1)cnt++;
		}
		cout << cnt;
		return 0;
	}
	
	
	//o(n^2)
	
	for(long long i = 1;i<=n;i++)
	{
		long long t = q[i-1] ^ a[i];
		q[i] = t;
	}
	
	for(long long i = 1;i<=n;i++)
	{
		for(long long j = 1;j<=i;j++)
		{
			long long t = q[j-1] ^ q[i];
			if(t == k)
			{
				f[i] = max(f[j-1] + 1,f[i]);
			}
			else f[i] = max(f[j-1],f[i]);
			//1~i中最多有多少个区间数量
		}
	}
	printf("%lld",f[n]);
	
	return 0;
} 

*/ 
