#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, m, x, r, c, now, a[105];
bool cmp(int l, int r){ return l > r; }
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
		cin >> a[i];
	x = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == x)
			x = i;
	}
	for(int i = 1;i <= m;i++){
		if(i & 1){
			for(int j = 1;j <= n;j++){
				a[(i - 1) * m + j] = ++now;
				if(now == x)
					cout << i << " " << j << endl; 
				}
		}
		else{
			for(int j = n;j >= 1;j--){
				a[(i - 1) * m + j] = ++now;
				if(now == x)
					cout << i << " " << j << endl; 
			}
		}
	}
	return 0; 
}

// Luogu Uid: 1062508 
