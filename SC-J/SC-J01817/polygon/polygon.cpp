#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;
int n, arr[N], ans=0;
void dfs(int a, int sumV)
{
	if(sumV > arr[a]) {
		ans++;
	}
	if (a == n) return;
	for (int i=a+1;i<=n;i++){
		dfs(i, sumV+arr[a]);
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> arr[i];
	sort(arr+1, arr+n+1);
	//for (int i=1;i<=n;i++) arr[i] += arr[i-1];
	for (int i=1;i<=n;i++){
		dfs(i, 0);
	}
	cout << ans;
	return 0;
}