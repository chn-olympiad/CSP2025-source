//11:09
//my DP is the worst in the world QAQ
//coach said this time T4 maybe tree or picture,so I just learnt them;;
#include <bits/stdc++.h>
using namespace std;
int n,a[114514*5],ans,cnt;
void dfs(int idx,int sum,int maxn) {
//	cnt++;
	if(sum > 2*maxn) ans++;
	if(idx >= n) return;
	for(int i = idx+1;i <= n;i++) dfs(i,sum+a[i],max(maxn,a[i]));
}
int main() {
	//TLE40
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	dfs(0,0,0);
	cout << ans;
	return 0;
}
