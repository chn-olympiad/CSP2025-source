#include <bits/stdc++.h>
#define cin fin
#define cout fout
#define endl '\n'
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
int n,a[100010][10];
long long ans;
void dfs(int pos,int x,int y,long long sum){
	if (pos > n){
		if (x <= n / 2 && y <= n / 2 && n - x - y <= n / 2)
			ans = max(ans,sum);
		return;
	}
	dfs(pos + 1,x + 1,y,sum + a[pos][1]);
	dfs(pos + 1,x,y + 1,sum + a[pos][2]);
	dfs(pos + 1,x,y,sum + a[pos][3]);
}
int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= 3;j++)
				cin >> a[i][j];
		dfs(1,0,0,0);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
