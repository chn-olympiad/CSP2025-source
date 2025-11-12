#include <bits/stdc++.h>
using namespace std;
int n,m,R;
int s[15][15],chengji[105],chengji2[105];
bool L = false;
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++) cin >> chengji[i];
	R = chengji[1];
	sort(chengji + 1,chengji + n*m + 1);
	//for(int i = 1;i <= n*m;i++) cout << chengji[i] << endl;
	int k = n * m;
	for(int i = 1;i <= n;i++){
		if(L){
			for(int j = m;j >= 1;j--){
				s[j][i] = chengji[k];
				k--;
			}
			L = false;
		}
		else{
			for(int j = 1;j <= m;j++){
				s[j][i] = chengji[k];
				k--;
			}
			L = true;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			//cout << s[i][j] << " ";
			if(s[i][j] == R){
				cout << j << " " << i;
			}
		}
		//cout << endl;
	}
}
