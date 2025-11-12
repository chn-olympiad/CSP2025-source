#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
long long a[N][5];
long long mn[N];
long long now[5];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	long long n, t;
	cin >> t;
	while (t--){
		cin >> n;
		long long ans = 0;
		
		for (int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		
		for (int i = 1; i <= n; i++){
			if (a[i][1] > a[i][2] && a[i][1] > a[i][3]){
				if (now[1] < n/2){
					now[1]++;
					mn[i] = 1;
				}else{
					if (a[i][2] > a[i][3]){
						now[2]++;
						mn[i] = 2;
					}else{
						now[3]++;
						mn[i] = 3;
					}
				}
				
			}else if (a[i][2] > a[i][1] && a[i][2] > a[i][3]){
				if (now[2] < n/2){
					now[2]++;
					mn[i] = 2;
				}else{
					if (a[i][1] > a[i][3]){
						now[1]++;
						mn[i] = 1;
					}else{
						now[3]++;
						mn[i] = 3;
					}
				}
			}else{
				if (now[3] < n/2){
					now[3]++;
					mn[i] = 3;
				}else{
					if (a[i][1] > a[i][2]){
						now[1]++;
						mn[i] = 1;
					}else{
						now[2]++;
						mn[i] = 2;
					}
				}
			}
		}
		
		for (int i = 1; i <= n; i++){
			int l = mn[i];
			ans = a[i][l] + ans;
		}
		cout << ans << endl;
	}
//	"1 4 4 2 1 3 2 4 5 3 4 3 5 1"
} 


