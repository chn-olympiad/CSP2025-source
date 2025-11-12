#include <bits/stdc++.h>
using namespace std;
int a[100005][4];
int t,n,ans = 0,b = 0,c = 0,d = 0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int x = 0;x < t;x++){
		cin >> n;
		for (int i = 0;i < n;i++){
			for (int j = 0;j < 3;j++){
			cin >> a[i][j];
			}
		}
		for (int o = 0;o < n;o++){
			if (a[o][0] >= a[o][1] && a[o][0] >= a[o][2] && b <= n/2){
				ans += a[o][0];
				b++;
			}
			else if (a[o][1] >= a[o][0] && a[o][1] >= a[o][2] && c <= n/2){
				ans += a[o][1];
				c++;
			}
			else if (a[o][2] >= a[o][0] && a[o][2] >= a[o][1] && d <= n/2){
				ans += a[o][2];
				d++;
			}
		cout << ans;
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}