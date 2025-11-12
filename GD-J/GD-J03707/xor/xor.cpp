#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 10;
vector <bool> x(MAX, true); 
struct node{
	int left, right;
};
bool cmp(node a, node b){
	return a.right - a.left < b.right - b.left;
}
bool check(int l, int r){
	for(int i = l; i <= r; i++){
		if(!x[i]) return false;
	}
	return true;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	vector <int> a(n+1);
	vector <node> R;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int sum = a[i];
			for(int p = i + 1; p <= j; p++){
				sum = sum ^ a[p];
			}
			if(sum == k){
				R.push_back({i, j});
			}
		}
	}
	sort(R.begin(), R.end(), cmp);
	int minn = n + 1, maxn = 0, ans = 0;
	for(int i = 0; i < R.size(); i++){
		if(check(R[i].left, R[i].right)){
			for(int q = R[i].left; q <= R[i].right; q++){
				x[q] = false;
			}
			ans++;
		}
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
