#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int a[N][N];

int main(){
	freopen("club.in","r", stdin);
	freopen("club.out","w", stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		int ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		int max[n];
		for(int i = 1; i <= n; i++){
			if(a[i][1] > a[i][2] && a[i][1] > a[i][3]){
				max[i] = a[i][1];
			}else{
				if(a[i][1] < a[i][3] && a[i][2] < a[i][3]){
					max[i] = a[i][3];
				}else{
					max[i] = a[i][2];
				}
			}
			ans += max[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
