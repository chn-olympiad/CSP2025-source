#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD = 998244353;

int g[5555];
int cnt[5555];
int sj[5005][5005];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(cnt, 0, sizeof(cnt));
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n; 
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> g[i];
		cnt[g[i]] ++;
	}
	
	sort(cnt, cnt + n);
	sort(g, g + n);
	
	sj[3][1] = 0, sj[3][2] = 0, sj[3][3] = 1;
	for(int i=3, as=3; i<=n+2; i++){
		sj[3][i+1] = sj[3][i] + as;
		as += i;
	}
	int d=0;
//	cout << sj[3][n] << " ";
	int a = 1 + sj[3][n], as;
	for(int i=4; i<n; i++){
		as = 0;
		for(int j = i - 1; j < n + d; j++){
			as += sj[i-1][j];
			sj[i][j+2] = as;
//			cout << sj[i][j+2] << " ";
//			sj[i][n-1] += sj[i-1][j+1];
		}
		a += as, d ++;
		a %= MOD;
	}
	cout << a;
//	if(cnt[n-1] == n){
//		
//	} else {
//		
//	}
	return 0;
}
