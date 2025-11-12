#include <bits/stdc++.h>
using namespace std;
int t, n, a[6][100001][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t >> n;
	if(n == 2){
		int maxn = 0;
		for(int i = 1;i <= t;i++){
			if(i!=1){
				cin >>n;
			}
			for(int j = 1;j <= n;j++){
				for(int k = 1;k <= 3;k++){
					cin >>a[i][j][k];
				}
			}
			for(int j = 1;j <= 3;j++){
				for(int k = 1;k <= 3;k++){
					if(j == k)continue;
					if(a[i][1][j]+a[i][2][k]>maxn){
						maxn = a[i][1][j]+a[i][2][k];
					}
				}
			}
			cout << maxn<<endl;
		}
	}
	else{
		int b[100001],maxn, m = 0;
		for(int i = 1;i <= t;i++){
			if(i!=1){
				cin >> n;
			}
			for(int j = 1;j <= n;j++){
				for(int k =1;k<=3;k++){
					if(k == 1){
						m++;
						cin >>b[m];
					}
					else{
						cin >> maxn;
					}
				} 
			}
			sort(b+1,b+m+1);
			maxn = 0;
			for(int j = m;j>m/2;j--){
				maxn += b[j]; 
			}
		}
		cout << maxn;
	}
	return 0;
}
