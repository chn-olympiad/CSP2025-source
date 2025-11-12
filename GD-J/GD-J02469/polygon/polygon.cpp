#include<bits/stdc++.h>
using namespace std;

const int N = 5010;
int a[N];
bool st[N];

int cnt = 0, sum = 0, maxa = 0, num = 0;
void dfs(int cur, int step, int len){
	if(step == len+1) return; 
	if(step == len) 
	step = len;
	if(num == step && sum > maxa * 2){
		cnt++;
		return;
	}else if(num == step) return;
	
	for(int i = cur; i <= len; i++){
		if(!st[i]){
			//ัก 
			int c = maxa;
			
			sum += a[i];
			maxa = max(maxa, a[i]);
			st[i] = true;
			num++;
			dfs(i+1, step, len);
		
			st[i] = false;
			sum -= a[i];
			maxa = c;
			num--;
		
			//ฒปัก 
			dfs(i+1, step, len);
		}
	}
	sum = 0;
	maxa = 0;
	num = 0;
	memset(st ,0, sizeof(st));
	cur = 0;
	dfs(1, step+1, len);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	dfs(1, 3, n);
	cout << cnt;
	return 0;
}
