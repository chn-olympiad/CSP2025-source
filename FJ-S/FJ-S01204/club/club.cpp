#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[3][105];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n;
		int club[3] = {0}, b;
		int favourite = 0;
		int maxn[105], maxx = 0;
		int sum = 0;
		for(int j = 1;j <= n;j++){
			maxx = 0;
			for(int k = 1;k <= 3;k++){
				cin >> a[k][j];
				if(a[k][j] > maxx){
					maxx = a[k][j];
					b = k;
				}
			}
			maxn[j] = maxx;
			club[b]++;
		}
		for(int k = 1;k <= 3;k++){
			if(club[k] > club[favourite]){
				favourite = k;
			}
		}
		if(club[favourite] <= n / 2){
			for(int j = 1;j <= n;j++){
				sum += maxn[j];
			}
			cout << sum << endl;
		}
	}
	return 0;
}

