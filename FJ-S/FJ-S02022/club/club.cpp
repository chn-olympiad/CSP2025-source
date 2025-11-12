#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int renshu;
	int a[renshu][3];
	int b[renshu][3];
	int zu;
	int ans = 0;
	int zu0;
	int zu1;
	int zu2;
	int zhuan;
	cin >> zu;
	for(int i = 0;i<zu;i++){
		cin >> renshu;
		for(int j = 0;j< renshu;j++){
			for (int x = 0;x< 3;x++){
				cin >> a[j][x];
				cin >> b[j][x];
				
			}
			for (int n = 0;n< 2;n++){
				for (int m = 0;m< 2;m++){
					if(b[j][m] < b[j][m+1]){
						zhuan = b[j][m];
						b[j][m] = b[j][m+1];
						b[j][m+1] = zhuan;
					}
				}
				
			}
			ans +=b[j][0];
		}
	}
	cout << ans;
	return 0;
}
