#include<bits/stdc++.h>
using namespace std;
int dx[2] = {1,-1};
int a[105],zw[20][20];
int x = 1,y = 1,c,n,m,t = 0;
int const N = 1e4 + 5;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n * m;i++){
		cin >> a[i];
	}
	c = a[0];
	sort(a,a + n * m);
	for(int i = n * m - 1;i >= 0;i--){
		zw[x][y] = a[i];
		if(a[i] == c){
			break;
		}
		if(x + dx[t] >= n + 1){
			y++;
			t = 1;
		}
		else if(x + dx[t] <= 0){
			y++;
			t = 0;
		}
		else{
			x += dx[t];
		}
	}
	cout << y << " " << x;
}

