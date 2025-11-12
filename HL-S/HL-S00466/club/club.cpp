#include<iostream>
#include<cmath>
using namespace std;
int a[10005][5],t,c[5];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;//1 4 4 2 1 3 2 4 5 3 4 3 5 1
	for(int ifor = 1;ifor <= t;ifor++){
		int n,num = 0,b[3];
		cin >> n;
		for(int i = 1;i <= 3;i++){
			b[i] = 0;
		}
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int amin = min(min(a[i][1],a[i][2]),a[i][3]);
			a[i][1] -= amin;
			a[i][2] -= amin;
			a[i][3] -= amin;
			if(a[i][1] == 0){
				a[i][4] = max(a[i][2],a[i][3]) - min(a[i][2],a[i][3]);
			}else if(a[i][2] == 0){
				a[i][4] = max(a[i][1],a[i][3]) - min(a[i][1],a[i][3]);
			}else if(a[i][3] == 0){
				a[i][4] = max(a[i][2],a[i][1]) - min(a[i][2],a[i][1]);
			}
			a[i][5] = amin;
		}
		int max4 = 0,maxi = 0;
		for(int i = 1;i < n;i++){
			for(int j = n;j >= i;j--){
				if(a[i][4] > max4){
					max4 = a[i][4];
					maxi = j;
				}
			}
			for(int ii = 1;ii <= 5;ii++){
				int t = a[i][ii];
				a[i][ii] = a[maxi][ii];
				a[maxi][ii] = t;
			}
			maxi = 0;
			max4 = 0;
		}
		int nn = n / 2;
		for(int i = 1;i <= n;i++){
			int d[2][3];
			for(int j = 1;j <= 3;j++){
				d[1][j] = a[i][j];
				d[2][j] = j;
			}
			if(d[1][1] > d[1][2] && d[1][1] > d[1][3]){
				if(d[1][2] > d[1][3]){
					int d1 = d[1][2];
					d[1][2] = d[1][3];
					d[1][3] = d1;
					d[2][2] = 3;
					d[2][3] = 2;
				}
			}else if(d[1][2] > d[1][1] && d[1][2] > d[1][3]){
				int d1 = d[1][2];
				d[1][2] = d[1][1];
				d[1][1] = d1;
				d[2][2] = 1;
				d[2][1] = 2;
				if(d[1][2] > d[1][3]){
					int d1 = d[1][2];
					d[1][2] = d[1][3];
					d[1][3] = d1;
					d[2][2] = 3;
					d[2][3] = 2;
				}
			}else if(d[1][3] > d[1][1] && d[1][3] > d[1][2]){
				int d1 = d[1][3];
				d[1][3] = d[1][1];
				d[1][1] = d1;
				d[2][3] = 1;
				d[2][1] = 3;
				if(d[1][2] > d[1][3]){
					int d1 = d[1][2];
					d[1][2] = d[1][3];
					d[1][3] = d1;
					d[2][2] = 3;
					d[2][3] = 2;
				}
			}
			for(int j = 1;j <= 3;j++){
				if(b[d[2][j]] + 1 < nn){
					b[d[2][j]] + 1;
					num += d[1][j] + a[i][5];
					break;
				}
			}
		}
//		for(int i = 1;i <= n;i++){
//			for(int j = 1;j <= 5;j++){
//				cout << a[i][j] << " ";
//			}
//			cout << endl;
//		}
		c[ifor] = num;
	}
	for(int i = 1;i <= t;i++){
		cout << c[i] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}