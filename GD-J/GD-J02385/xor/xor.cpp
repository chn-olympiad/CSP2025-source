#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n,k;
int arr[N]; 

int cost[1005][1005];
bool vis[N];

int func(int s, int e){
	int ans = 0;
//	if (s > e){
//		int w = s;
//		s = e;
//		e = w;
//	}
	for (int i = s; i <= e; i ++){
		ans ^= arr[i];
	}
	return ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++){
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= n; j ++){
			cost[i][j] = func(i,j);
		}
	}
//	for (int i = 1; i <= n; i ++){
//		for (int j = 1; j <= n; j ++){
//			cout << cost[i][j] << ' ';
//		}
//		cout << endl;
//	}
	int cnt = 0;
	
	for (int i = 1; i <= n; i ++){
		for (int j = i; j <= n; j ++){
			if (cost[i][j] == k){
//				cout << i << ' ' << j << endl;
				bool flag = 1;
				for (int k = i; k <= j; k ++){
					if (vis[k]) flag = 0;
					break;
				} 
				if (flag){
					for (int k = i; k <= j; k ++){
						vis[k] = 1;
					}
//					cout << i << ' ' << j << endl;
					cnt ++;
				}
			}
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
