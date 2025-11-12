#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int n,ans;
int a[5003];
void dfs(int pos, int mx, int sum)
{
	if(sum>mx*2)
	{
		ans++;
		ans%=998244353;
//		cout<<sum;
	}
	for(int i = pos+1;i<=n;i++)
	{
		dfs(i, max(mx, a[i]), sum+a[i]);
//		dfs(i, mx, sum);
	}
}
int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(max(max(a[1],a[2]),a[3])*2 < a[1]+a[2]+a[3])
			cout<<1;
		else
			cout<<0;
	}
	else
	{
		dfs(0, 0, 0);
		cout<<ans;
	}
	return 0;
}
