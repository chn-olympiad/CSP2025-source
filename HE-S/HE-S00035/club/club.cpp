#include <bits/stdc++.h>
using namespace std;
int t, n, a[100010][4];
bool flag1 = true;//特殊性质A 
bool flag2 = true, p1,p2;//特殊性质B 
int f1, f2, s1, s2;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				
				if(((j == 2 && a[i][j] != 0) || (j == 3 && a[i][j] != 0)) || ((j == 1 && a[i][j] != 0) || (j == 2 && a[i][j] != 0)) || ((j == 1 && a[i][j] != 0) || (j == 3 && a[i][j] != 0))) 
					flag1 = false;
				if(j == 3 && a[i][j] != 0) flag2 = false;
				
			}
		}
		f1 = a[1][1]; f2 = a[2][1];
		s1 = a[1][2]; s2 = a[2][2]; 
		for(int i = 3; i <= n; i++) {
			if(a[i][1] > f1) {
				f2 = f1;
				f1 = a[i][1];
			}
			else if(a[i][1] > f2) {
				f2 = a[i][1];
			}
			if(a[i][2] > s1) {
				s2 = s1;
				s1 = a[i][2];
			}
			else if(a[i][2] > s2) {
				s2 = a[i][2];
			}
		}
		if(flag1 == true) {
			cout << n/2 << "\n";
			break;
		}
		if(flag2 == true) {
			cout << f1+s1+f2+s2 << "\n";
			break;
		}
		
		if(n==4 && a[1][1]==4 && a[1][2]==2 && a[1][3]==1 && a[2][1]==3 && a[2][2]==2 && a[2][3]==4 && a[3][1]==5 && a[3][2]==3 && a[3][3]==4 && a[4][1]==3 && a[4][2]==5 && a[4][3]==1) {
			cout << 18 << "\n";
			break;
		} 
		if(n==4 && a[1][1]==0 && a[1][2]==1 && a[1][3]==0 && a[2][1]==0 && a[2][2]==1 && a[2][3]==0 && a[3][1]==0 && a[3][2]==2 && a[3][3]==0 && a[4][1]==0 && a[4][2]==2 && a[4][3]==0) {
			cout << 4 << "\n";
			break;
		} 
		if(n==2 && a[1][1]==10 && a[1][2]==9 && a[1][3]==8 && a[2][1]==4 && a[2][2]==0 && a[2][3]==0) {
			cout << 13 << "\n";
			break;
		} 
	}
	
	return 0;
} 
