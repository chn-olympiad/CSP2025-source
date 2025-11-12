#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 5010;
int n,sum,chk;
int a[N];
//vector <int> ans;
bool cmp(int a1,int a2){
	return a1 < a2;
}
void dfs(int ii,int sum_stk,int len_stk,int now_n){
	if (sum_stk == now_n){
//		for (int i = 0;i < ans.size();i++){
//			cout << ans[i] << ' ';
//		}cout << '\n';
		++sum;
		return;
	}
	for (int i = ii;i <= n;i++){
//		for (int i = 0;i < ans.size();i++){
//			cout << ans[i] << ' ';
//		}cout << "*\n";
		if (sum_stk < now_n - 1 || a[i] < len_stk){
//			ans.push_back(a[i]);
			dfs(i + 1,sum_stk + 1,len_stk + a[i],now_n);
//			ans.pop_back();
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	freopen ("polygon.in","r",stdin);
//	freopen ("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] != 1)chk = 1;
	}
	if (!chk){
		cout << (n + 1) * n / 2;
		return 0;
	}
	stable_sort(a + 1,a + 1 + n,cmp);
	for (int i = 3;i <= n;i++){
		dfs(1,0,0,i);
	}
	cout << sum;
	return 0;
}
