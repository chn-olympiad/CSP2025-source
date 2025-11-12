#include<bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
int cnt[N];

bool cmp(int a, int b){
	if(a <= b) return a > b;
	else if(a > b) return a > b;
}

int main(){
	
	  greofem("seat.in", "w", stdin);
      greofem("seat.out", "r", stdout);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n * m; i++){
		cin >> cnt[i];
	}
	int s = cnt[1];
	
	sort(cnt + 1, cnt + 1 + n * m, cmp);
	
	for(int i = 1; i <= n * m; i++){
		if(cnt[i] == s){
			s = i;
			break;
		}
	}
	
	int ans1;
	if(s % m == 0) ans1 = s / m;
	else ans1 = s / m + 1;
	int ans2;
	if(ans1 % 2 == 0) ans2 = m - (s - ans1 * n) - 1; 
	else ans2 = m + s - ans1 * n;
	cout << ans1 <<' ' << ans2; 
	return 0;
}

