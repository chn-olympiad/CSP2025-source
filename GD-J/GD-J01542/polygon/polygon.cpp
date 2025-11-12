
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int MAXN = 500005;
const int MOD = 998244353 ;
int a[MAXN];
int vis[MAXN];
map<vector<int>,int> mp;
int n;
int sum,mx;
int cnt = 0;
int linx(int x)
{
	int sum =1;
	for(int i = 2;i <= x;i++)
		sum = (sum*x)%MOD;
}
void dfs(int x,vector<int> v)//预计 32-40pts
{
	if(sum > mx*2)
	{
		if(mp[v] == 0)
		{
			cnt++;
			mp[v] = 1;
		}
	}
	if(x > n)
		return;
	int tmp1 = sum,tmp2 = mx;
	sum+=a[x];
	mx = max(mx,a[x]);
	v.push_back(x);
	dfs(x+1,v);
	sum = tmp1;
	mx = tmp2;
	v.pop_back();
	dfs(x+1,v);
}
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag1  =true;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		if(a[i] != 1)
			flag1 = false;
	}
	if(flag1)
	{
		int ans = 0;
		for(int i = 1;i <= n;i++)
			for(int j = i+1;j <= n;j++)
				for(int k = j+1;k<=n;k++)
					for(int z = k+1;z<= n;z++)
						
		cout<<ans;
		return 0;
	}
	dfs(1,{});
	cout<<cnt;
	return 0;
}//CCF你牛大了，T4爆搜你给40分 

