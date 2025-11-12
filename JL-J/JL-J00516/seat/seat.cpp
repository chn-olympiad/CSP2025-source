#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[1000][1000];
	int n,m,for_R;
	cin >> n >> m >> for_R;
	int grade[1000];
	grade[1] = for_R;
	for(int i = 2; i <= n*m; i++) cin >> grade[i];
	sort(grade+1, grade+(n*m)+2, cmp);
	int k = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; i%2 && j <= m; j++){
			a[j][i] = grade[k];
			k++;
			if(a[j][i] == for_R){
				cout << i << " " << j;
				return 0;
			}
		}
		for(int j = m; !(i%2) && j >= 1; j--){
			a[j][i] = grade[k];
			k++;
			if(a[j][i] == for_R){
				cout << j << " " << i;
				return 0;
			}
		}
	}
}
