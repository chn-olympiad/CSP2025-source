#include<bits/stdc++.h> 
using namespace std;
const int N = 1e4+5;
int a[N][N],ma = 0,mi = 0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin >>n;
	int m;
	while(n--){
		cin >> m;
		mi = 0;
		for(int i = 1;i<=m;i++){
			for(int j = 1;j<=3;j++){
				cin >> a[i][j];
			} 
		}
		for(int i = 1;i<=m;i++){
			ma = 0;
			for(int j = 1;j<=3;j++){
				if(a[i][j] > ma){
					ma = a[i][j];
					cout << ma << "*" << '\n';
				}
			} 
			mi += ma;
		}
		cout << mi << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
