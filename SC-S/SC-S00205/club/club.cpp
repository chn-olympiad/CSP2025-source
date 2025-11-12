#include <bits/stdc++.h>
using namespace std;


const int N = 1e6+9;

int n;
int ans1 = 0,ans2 = 0,ans3 = 0,maxn = 0,s = 0;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	
	cin >> t;
	
	while (t--) {
		cin >> n;
		int a[N][N];
		
		vector<int>b;
			
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				
				if (a[i][2] == a[i][3] && a[i][2] == 0) {
					for (int k = 1; k <= n;k++) {
						b[i] = a[i][1];
					}
					
					sort(b.begin(),b.end());
					
					for (int i = 1; i <= n / 2; i++) {
						maxn += b[i];
					}
					
					cout << maxn << endl;
					return 0;
				}
			}
		}
	}
	
	return 0;
		
}