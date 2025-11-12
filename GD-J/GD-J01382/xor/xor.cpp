#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],ans = 0,maxn = -1,n,k;
#define MAXN 998244353
bool check(int i,int j,int sum)
{
	int tp = sum^a[j];
	//cout << tp;
	return tp == k;
}

void dfs(int i,int j,int sum){
	if(i > n || j > n){
		maxn = max(maxn,ans);
		return;
	}
	if(check(i,j,sum))
	{
		//cout << sum << " " << a[i] << endl;
		ans=(ans+1);
		//dfs(i,j+1,sum^a[j]);
		dfs(j+1,j+1,0);
	}
	else
	{
		int tp = ans;
		dfs(i,j+1,sum^a[j]);
		ans = tp;
		dfs(j+1,j+1,0);
	}
}

signed main()
{
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int temp = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] == 0) temp++;
	}
	if(k == 0)
	{
		cout << temp;
		return 0;
	}
	dfs(1,1,0);
	cout <<maxn;
	return 0;
}
