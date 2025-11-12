#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int e,t,n,cnt,c;
int a[N][4],f[N];

bool cmp(int a,int b) {
	return a > b;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	while(t--) {
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f)); 
		cin >> n;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		
		int res = 0;
		if(n <= 3) {
			for(int i = 1; i <= n; i++) {
				int temp = 0;
				for(int j = 1; j <= 3; j++)
					temp = max(temp,a[i][j]);
				res += temp;
			}
			cout << res << endl;
			continue;
		}
		
		cnt = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				if(a[i][j] != 0) {
					f[++cnt] = a[i][j];
				}
			}
		}
		sort(f+1,f+1+cnt,cmp);
		int sum = 0;
		for(int i = 1; i <= (cnt / 2); i++) {
			sum += f[i];
		}
		cout << sum << endl;
	}
	
	return 0; 
} 
