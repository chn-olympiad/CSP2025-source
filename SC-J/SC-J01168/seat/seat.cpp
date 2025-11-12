#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[1005];
int c[105][105];
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int xa = 0;
	for(int i = 1;i <= n * m;i ++){
		cin >> a[i];
	}
	xa = a[1];
	sort(a + 1, a + n * m + 1, greater<int> () );
	int tot = 0;
	for(int i = 1;i <= m;i ++){
		if(i % 2 == 1){
			for(int j = 1;j <= n;j ++){
				c[j][i] = a[++ tot];
			}	
		}
		else{
			for(int j = n;j >= 1;j --){
				c[j][i] = a[++ tot];
			}
		}
	}
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= n;j ++){
			if(c[j][i] == xa){
				cout << i << " " << j << endl;
				return 0;
			}
//			cout << c[i][j] << " ";
		}
//		cout << endl;
	}
	return 0;
}
/*
2 2
99 100 97 98
2 2
98 99 100 97
7 5
78 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 77 76 75 74 73 72 71 70 69 68 67 66
*/