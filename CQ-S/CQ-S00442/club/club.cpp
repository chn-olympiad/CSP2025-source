#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pair;
ll ans;
int n;
void dfs(vector<vector<int> > &a , int k , ll cnt , int x , int y , int z)
{
	if(x > n / 2 or y > n / 2 or z > n / 2) return;
	if(k > n)
	{
		ans = max(ans , cnt);
		return;
	}
	dfs(a , k + 1 , cnt + a[k][1] , x + 1 , y , z);
	dfs(a , k + 1 , cnt + a[k][2] , x , y + 1 , z);
	dfs(a , k + 1 , cnt + a[k][3] , x , y , z + 1);
}
void solve()
{
	cin >> n;
	vector<vector<int> > a(n + 5 , vector<int>(5 , 0));
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	ans = 0;
	dfs(a , 1 , 0 , 0 , 0 , 0);
	cout << ans << endl;
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}

