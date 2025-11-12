#include <bits/stdc++.h> 
using namespace std;
const int N = 1e5 + 5;
int T;
int a[4][N];
int t[5], num[5];
int number;
void solve(){
	int n;
	scanf("%d", &n);
	memset(t, 0, sizeof(t));
	memset(a, 0, sizeof(a));
	memset(num, 0, sizeof(num));
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
	}
	for(int i = 1; i <= n; i++){
		if(i < n) number = a[i+ 1][1] + a[i + 1][2] + a[i + 1][3];
		
		if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
			if(num[1] + 1 > n / 2 || number == a[i + 1][1]){
				if(a[i][2] > a[i][3]) t[2] += a[i][2], num[2]++;
				else t[3] += a[i][3], num[3]++;
				continue;
			}
			num[1]++;
			t[1] += a[i][1];
		}else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
			if(num[2] + 1 > n / 2 || number == a[i + 1][2]){
				if(a[i][1] > a[i][3]) t[1] += a[i][1], num[1]++;
				else t[3] += a[i][3], num[3]++;
				continue;
			}
			num[2]++;
			t[2] += a[i][2];
		}else if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2]){
			if(num[3] + 1 > n / 2 || number == a[i + 1][3]){
				if(a[i][2] > a[i][1]) t[2] +=a[i][2], num[2]++;
				else t[1] += a[i][1], num[1]++;
			}
			num[3]++;
			t[3] += a[i][3];
		}
	}
//	cout << num[1] << ' ' << num[2] << ' ' << num[3] << endl;
	cout << t[1] + t[2] + t[3] << endl;
	
} 
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "out", stdout);
	scanf("%d", &T);
	while(T--){
		solve();
	}
	return 0; 
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

