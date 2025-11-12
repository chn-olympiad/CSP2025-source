#include<bits/stdc++.h>
using namespace std;
int seats[15][15];
int a[105],n,m,scoreSelf,numSelf;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> a[i];
	}
	scoreSelf = a[1];
	sort(a + 1,a + n * m + 1,greater<int>());
	int pos = 1;
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= n;j ++){
			if(i % 2 == 1)
				seats[i][j] = a[pos ++];
			else
				seats[i][n - j + 1] = a[pos ++];
		}
	}
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= n;j ++){
			if(seats[i][j] == scoreSelf){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
