#include<bits/stdc++.h>
using namespace std;
int n, m, a[105], ans[15][15], c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	int p = n*m, b = a[1];
	sort(a+1,a+p+1);
	for(int i = 1;i <= m;i++){
		if(c % 2 == 0){
			for (int j = 1;j <= n;j++){
				ans[i][j] = a[p--];
				if(ans[i][j] == b){
					cout << i << " " << j;
					break;
				}
			}
		}
		else{
			for (int j = n;j >= 1;j--){
				ans[i][j] = a[p--];
				if(ans[i][j] == b){
					cout << i << " " << j;
					break;
				}
			}
		}
		c++;
	}
	return 0;
}
