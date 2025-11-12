#include<bits/stdc++.h>

using namespace std;

int a[15][15],a2[300];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a2[i];
	}
	int temp = n*m,t = a2[1],w = 1;
	sort(a2+1,a2+1+temp,cmp);
	int y,z = 1;
	while(z <= m){
		y = 1;
		while(y <= n){
			a[y][z] = a2[w];
			w++;
			y++;
		}
		z++;
		y = n;
		while(y>=1){
			a[y][z] = a2[w];
			w++;
			y--;
		}
		z++;
	}
	
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i][j] == t){
				cout << j << " " << i;
				return 0; 
			}
		}
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

4 5
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/
