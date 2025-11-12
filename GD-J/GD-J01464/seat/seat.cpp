#include <bits/stdc++.h>
using namespace std;
int a[110];
int b[20][20];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int cnt = n*m;
	for(int i = 1;i <= cnt;i++){
		cin >> a[i];
	}
	int k = a[1];
	sort(a+1, a+cnt+1, greater<int>());
	int q = 0;
	for(int i = 1;i <= cnt;i++){
		if(a[i] == k){
			q = i;
			break;
		}
	}
	int p = 0, v = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(j == 1){
				b[i][j] = ++p;
			}else{
				if(j % 2 == 0){
					b[i][j] = b[i][j-1] + 2*n-v;
				}else{
					b[i][j] = b[i][j-1] + v;
				}
			}
			
		}
		v += 2;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(b[i][j] == q){
				cout << j << " " << i << "\n";
				break;
			}
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
