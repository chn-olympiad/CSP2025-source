#include<bits/stdc++.h>
using namespace std;
int a[100004][4] = {0};
int sum[5] = {0};
int n,t;
int max_ans = 0;
void dfs(int ans,int xs){
	if(xs == n + 1) max_ans = max(ans,max_ans);
	else{
		int r;
		if(a[xs][1] < a[xs][2] && a[xs][1] < a[xs][3]) r = 1;
		if(a[xs][2] < a[xs][1] && a[xs][2] < a[xs][3]) r = 2;
		if(a[xs][3] < a[xs][2] && a[xs][3] < a[xs][1]) r = 3;
		for(int i = 1;i <= 3;i ++){
			if(i == r) continue;
			if(sum[i] < n / 2){
				ans += a[xs][i];
				sum[i] ++;
				dfs(ans,xs + 1);
				ans -= a[xs][i];
				sum[i] --;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t --){
		max_ans = 0;
		for(int i = 1;i <= 3;i ++) sum[i] = 0;
		cin >> n;
		for(int i = 1;i <= n;i ++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(0,1);
		cout << max_ans << endl;
	}
	return 0;
}
