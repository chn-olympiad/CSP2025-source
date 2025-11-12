#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5 + 10;
int a[N];
int st[N];
int pre[N];

int n, k, num = 0, sum = 0, cnt = 0;
void dfs(int step){
	if(num == step){
		if(sum == k) cnt++;
		return;
	}
	
	for(int i = 1; i <= n; i++){
		if(!st[i]){
			if(sum == 0) sum += a[i];
			else sum ^= a[i];
			num++;
			st[i] = true;
			dfs(step);
			sum ^= a[i];
			num--;
			dfs(step);
		}
	}
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = pre[i-1] ^ a[i];
	}
	
	for(int i = 1; i <= n; i++){
		memset(st, 0 ,sizeof(st));
		dfs(i);
	}
	cout << cnt;
	return 0;
}
