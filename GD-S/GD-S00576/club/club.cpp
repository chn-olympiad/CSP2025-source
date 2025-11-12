#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int arr[N][N];
bool vis[N][N];
int ans[N];
int t, n, maxx = 0, sum = 0, num, m, pans;
int l, r;

//bool check(int s){
//	int x = 0, p1 = 0, p2;
//	for(int j = 0; j < t; j++){
//		p2 = 0;
//		for(int k = 0; k < n; k++){
//			if((x+arr[j][k] <= s) && (p1 < n) && (p2 < num)){
//				p1++;
//				p2++;
//				x+=arr[j][k];
//				cout << "p2:" << p2 << endl;
//				cout << "p1:" << p1  << "n:" << n << endl;
//			}
//		}
//	}
//	return p1 == n; 
//}

//int getMax(int arr[N][N], int y){
//	int max2 = 0;
//	for(int i = 0; i < t; i++){
//		for(int j = 0; j < n; j++){
//			if(!vis[i][j]){
//				max2 = max(max2, arr[i][y] + arr[j][y]);
//			}
//		}
//	}
//	return max2;
//}

//bool check(int s){
//	int x = 0, ps = 0, ps2 = 0;
//	for(int j = 0; j < t; j++){
//		ps = 0;
//		for(int k = 0; k < n; k++){
//			
//			if(getMax(arr, k) <= s && ps < num && ps2 < n){
//				x+= getMax(arr, k);
//				ps++;
//				ps2++;
//				for(int i = 0; i < t; i++){
//					vis[k][i] = true;
//				}
//			}
//		}
//	}
//	return ps2 == n;
//}

bool check(int s){
	int x = 0, ps = 0, ps2 = 0;
	for(int i = 0; i < n; i++){
		x = arr[i][0];
		for(int j = 1; j < n; j++){
			ps2 = 0;
			for(int k = 0; k < t; k++){
				if(!vis[i][k] && !vis[j][k]){
					if(x+arr[j][k] < s && ps < num && ps2 < n){
						x+=arr[j][k];
						ps++;
						ps2++;
//						cout << "x:" << x << endl;
//						cout << "ps:" << ps << endl;
//						cout << "ps2:" << ps2 << endl;
//					}
					}
				}
			}
		}
	}
	return ps2 == n;
}


int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int i = 0; i < t; i++){
		sum = 0, maxx = 0;
		cin >> n;
		num = n/2;
		for(int j = 0; j < n; j++){
			maxx = 0;
			for(int k = 0; k < t; k++){
				cin >> arr[j][k];
				maxx = max(maxx, arr[j][k]);
			}
			sum += maxx;
		}
		l = 0, r = sum;
//		cout << "sum: " << sum << endl;
		while(l < r){
			m = (r+l)/2;
			if(check(m)){
				r = m-1;
				pans = m;
//				cout << "pans:" << pans << endl;
			}
			else{
				l = m+1;
//				cout << "m:" << m << endl;
			}
		}
		ans[i] = sum;
		pans = 0; 
		for(int u = 0; u < t; u++){
			for(int v = 0; v < n; v++){
				vis[u][v] = false;
			}
		}
	}
	for(int i = 0; i < t; i++){
		cout << ans[i] << endl;
	}
	return 0;
}




