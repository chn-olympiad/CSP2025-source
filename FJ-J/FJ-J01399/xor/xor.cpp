// 10:05
// 异或的题确实不会写
// ...

// 11:09
// 骗完了T4
// 来写神秘的T3
// 目前想法是骗完sp.A和sp.b就收手
// 睡觉去了 

// 11.28
// 骗完了
// 可以看出我确实菜
// 睡觉去了
// 甚至三个样例都过了
// 笑死了
// 到时候就说样例过了答案居然10分()
 
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1<<20;
int a[MAXN],ans;

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	if(n==1)
	{
		int t;
		cin >> t;
		if(t!=0)
		{
			cout << 0;
			return 0;
		}
		cout << 1;
		return 0;
	}
	if(n==2)
	{
		int a,b,ans=0;
		cin >> a >> b;
		if(a!=b) ans=1;
		if(a==0) ans++;
		if(b==0) ans++;
		if(a==0&&b==0) ans=2;
		cout << ans;
		return 0;
	}
	// 骗 task 1 
	
	bool tp=true;
	bool only0and1=true;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		if(a[i]!=a[i-1])
		{
			tp=false;
		}
		if(a[i]>=2)
		{
			only0and1=false;
		} 
	}
	if(tp)
	{
		cout << n/2;
		return 0;
	}
	// 骗sp.A 
	
	if(only0and1)
	{
		int sum0=0,sum1=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)sum0++;
			if(a[i]==1)sum1++;
		}
		if(k==0)
		{
			cout << sum0;
			return 0;
		}
		cout << sum1;
		return 0;
	}
	// 骗sp.B 感觉不咋对 
	
	int cnt=a[1];
	if(cnt==k) cnt=a[2];
//	if(a[1]==k) ans++;
	for(int i=1; i<n; i++)
	{
		cout << cnt << endl;
		if(a[i]==k)
		{
			ans++;
			cnt=a[i+1];
			continue;
		}
		cnt^=a[i+1];  
		if(cnt==k)
		{
			ans++;
			cnt=a[i+1];
		}
	}
	if(a[n]==k) ans++;
	cout << ans << endl;
	return 0;
}


