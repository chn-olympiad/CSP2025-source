#include<bits/stdc++.h>
using namespace std;
int T , n , a[100500][9] , cl[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	for(int i = 1 ; i <= T ; i++){
		int sum = 0;
		cin >> n;
		int maxx = n / 2;
		for(int j = 1 ; j <= n ; j++){
			cin >> a[j][1] >> a[j][2] >> a[j][3];
			if(a[j][1] >= a[j][2] && a[j][1] >= a[j][3] ){
				a[j][4] = 1;
				if(a[j][2] >= a[j][3])
					a[j][5] = 2 , a[j][6] = 3 , a[j][7] = a[j][1]-a[j][2];
				else a[j][5] = 3 , a[j][6] = 2 , a[j][7] = a[j][1]-a[j][3];
			}
			else if(a[j][2] >= a[j][3]) {
				a[j][4] = 2;
				if(a[j][1] >= a[j][3])
					a[j][5] = 1 , a[j][6] = 3 , a[j][7] = a[j][2]-a[j][1];
				else a[j][5] = 3 , a[j][6] = 1 , a[j][7] = a[j][2]-a[j][3];
			}
			else if(a[j][1] >= a[j][2]) a[j][4] = 3 , a[j][5] = 1 , a[j][6] = 2 , a[j][7] = a[j][3]-a[j][1];
			else a[j][4] = 3 , a[j][5] = 2 , a[j][6] = 1 , a[j][7] = a[j][3]-a[j][2];
			a[j][8] = a[j][4];
		}
		for(int j = 1 ; j <= n ; j++){
			if(cl[a[j][4]] < maxx)
				 cl[a[j][4]]++;
			else{
				int o = 0;
				int now = a[j][7];
				for(int k = 1 ; k < j ; k++){
					if(now > a[k][7] && a[k][8] == a[j][8]){
						now = a[k][7];
						o = k;
					}
					if(now == a[k][7] && a[k][8] == a[j][8]){
						if(a[j][5] < a[k][5]){
							now = a[k][7];
							o = k;
						}
					}
				}
				if(o){
					a[o][8] = a[o][5];
				}
				else{
					cl[a[j][5]]++;
					a[j][8] = a[j][5];
				}
			}
		}
		for(int j = 1 ; j <= n ; j++){
			sum += a[j][ a[j][8] ];
		}
		cout << sum << endl;
		for(int j = 0 ; j <= n ; j++){
			for(int k = 0 ; k <= 7 ; k++)
				a[j][k] = 0;
		}
		cl[0] = cl[1] = cl[2] = cl[3] = 0;
	}
	return 0;
}
