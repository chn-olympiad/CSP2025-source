#include<iostream>
#include<algorithm>
using namespace std;

int n,ans;
int a[505];

void dfs(int x,int maxn,int sum){
	if (maxn * 2 < sum){
		ans++;
	}
	for (int i = x + 1;i <= n;i++){
		dfs(i,max(a[i],maxn),sum+a[i]);
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool flag = true;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] != 1) flag = false;
	}
	if (flag and n > 20){
		for (int i = 3;i <= n;i++){
			int cnt = 1;
			for (int j = n;j >= i;j--){
				cnt *= j;
			}
			for (int j = i;j >= 1;j--){
				cnt /= j;
			}
			ans += cnt;
		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout << ans;
}
