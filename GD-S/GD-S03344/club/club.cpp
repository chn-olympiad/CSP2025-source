#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 0;i <= t - 1;i++){
		int n;
		cin >> n;
		int a[n][3],b[3] = {0,0,0},c[3] = {0,0,0},s = n / 2;
		for(int j = 0;j <= n - 1;j++){
			for(int k = 0;k <= 2;k++){
				cin >> a[j][k];
			}
		}
		for(int j = 0;j <= n - 1;j++){
			if(a[j][0] > a[j][1] && a[j][0] > a[j][2] && c[0] <= s){
				c[0]++;
				b[0] += a[j][0];
			}
			else if(a[j][1] > a[j][0] && a[j][1] > a[j][2] && c[1] <= s){
				c[1]++;
				b[1] += a[j][1];
			}
			else if(a[j][2] > a[j][0] && a[j][2] > a[j][1] && c[2] <= s){
				c[2]++;
				b[2] += a[j][2];
			}
			else if((a[j][0] < a[j][1] && a[j][0] > a[j][2] && c[0] <= s && c[1] > s) || (a[j][0] < a[j][2] && a[j][0] > a[j][1] && c[0] <= s && c[2] > s)){
				c[0]++;
				b[0] += a[j][0];
			}
			else if((a[j][1] < a[j][0] && a[j][1] > a[j][2] && c[1] <= s && c[0] > s) || (a[j][1] < a[j][2] && a[j][1] > a[j][0] && c[1] <= s && c[2] > s)){
				c[1]++;
				b[1] += a[j][1];
			}
			else if((a[j][2] < a[j][0] && a[j][2] > a[j][1] && c[2] <= s && c[0] > s) || (a[j][2] < a[j][1] && a[j][2] > a[j][0] && c[2] <= s && c[1] > s)){
				c[2]++;
				b[2] += a[j][2];
			}
		}
		cout << b[0] + b[1] + b[2] << endl;
	}
	return 0;
}
