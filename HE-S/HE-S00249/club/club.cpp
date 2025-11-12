#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
struct Student {
	int my1, my2, my3;
	char g;
}arr[2*N];
int t, n, ac, bc, cc, ans;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> arr[i].my1 >> arr[i].my2 >> arr[i].my3;
			if(arr[i].my1 > arr[i].my2 && arr[i].my1 > arr[i].my3){
				arr[i].g = 'a';
			}
			else if(arr[i].my2 > arr[i].my1 && arr[i].my2 > arr[i].my3){
				arr[i].g = 'b';
			}
			else{
				arr[i].g = 'c';
			}
			if(ac <= n / 2 && bc <= n / 2 && cc <= n / 2) {
				for(int i = 1; i <= n; i++) {
					if(arr[i].g == 'a') ans += arr[i].my1;
					if(arr[i].g == 'b') ans += arr[i].my2;
					if(arr[i].g == 'c') ans += arr[i].my3;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
