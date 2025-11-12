#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 5000 + 42;
int n,a[MAXN] = {0},ans = 0;
 
void dfs(int dep,int sum)
{
	if(dep >= 3 && sum > a[dep] * 2) ans++;
	for(int i = dep + 1;i <= n;i++) dfs(i,sum + a[i]);
	
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a+n + 1);
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
