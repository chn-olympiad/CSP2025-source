#include<bits/stdc++.h>
using namespace std;
int a[15][15], score[105];
int cnt=1;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, k;
	cin >> n >> m;
	for (int i=1; i<=n*m; i++){
		cin >> score[i];
	}
	sort(score+2, score+n*m+1, cmp);
	k = score[1];
	for (int i=1; i<=n; i++){
		if (i%2!=0){
			for (int j=1; j<=m; j++){
				cnt++;
				if (score[cnt]>k) a[i][j] = score[cnt];
				else{
					cout << i << " " << j << '\n';
					return 0;
				}
			}
		}else{
			for (int j=m; j>=1; j--){
				cnt++;
				if (score[cnt]>k) a[i][j] = score[cnt];
				else{
					cout << i << " " << j << '\n';
					return 0;
				}
			}
		}
	}
	return 0;
}
