#include<bits/stdc++.h>
using namespace std;

long long N = 998244353;

long long n;
long long a[6000];

long long List[6000];

bool flag;
long long kill;

long long ans;

bool cmp(long long a,long long b)
{
	return a > b;
}

long long POW(long long a,long long b)
{
	long long sum = 1;
	for(long long i = 1; i <= b; i++) sum = sum * a % N;
	
	return sum;
}

void dfs(long long x,long long sum,long long big,long long cnt)
{
	if(x > n) //如果到最后都没找到标记，不要第一个最大 
	{
		flag = true;
		return ;
	}
	
	kill = x;
	if(sum + a[x] > 2 * big && cnt >= 2)
	{
		ans = (long long)(ans + (long long)POW(2,n - x) % N) % N;
		dfs(x + 1,sum,big,cnt);
		if(x == kill) flag = false;
		return ; 
	}
	
	dfs(x + 1,sum + a[x],max(big,a[x]),cnt + 1);
	
	if(flag == true) 
	{
		if(x == kill) flag = false;
		return ;
	}
	
	dfs(x + 1,sum,big,cnt);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	
	long long luo = 0;
	
	for(long long i = 1; i <= n; i++) 
	{
		cin >> a[i];
		luo = max(luo,a[i]);
	}
	
	if(luo == 1) 
	{
		List[1] = 1;
		for(long long i = 2; i <= n; i++) List[i] = List[i - 1] * i % N;
		for(long long i = n; i >= 3; i--)
		{
			if(n == i) ans++;
			else ans = (ans + List[n] / (List[i] * List[n - i]) % N) % N;
		}
		cout << ans;
		return 0;
	}
	
	sort(a + 1,a + n + 1,cmp);
	
	dfs(1,0,0,0);
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
