#include <bits/stdc++.h>
using namespace std;
int a[150];
int b[15][15];
int cnt;

int main(){
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> a[i];
	}
	freopen("seat.in","r",stdin);
	int y = n*m;
	int ans = a[1];
	sort(a+1,a+y+1,greater<int>());
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cnt++;
			b[i][j] = a[cnt];
			if(b[i][j] == ans){
				if(i % 2 == 1){
				    cout << i << " " << j;
				}else{
					cout << i << " " << m - j;
				}
				return 0;
			}
		}
	}
    return 0;
}

