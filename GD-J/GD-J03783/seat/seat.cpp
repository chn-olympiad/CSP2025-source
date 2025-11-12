#include<bits/stdc++.h>
using namespace std;
int n,m,a[17][17],sc[207];
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,1};
int x,y,suma,t,sum,num,numa;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> sc[i];
	}
	num = sc[1];
	sort(sc + 1,sc + 1 + n * m,cmp);
	for(int i = 0;i <= n + 1;i++){
		for(int j = 0;j <= m + 1;j++){
			if(i < 1 || i > n || j < 1 || j > m){
				a[i][j] = -1;
			}
		}
	}
	sum = n * m;
	x = 0;
	y = 1;
	t = -1;
	suma = m;
	while(sum--){
		t = (t + 1) % 4;
		while(suma--){
			x += dx[t];
			y += dy[t];
			a[x][y] = sc[++numa];
			if(sc[numa] == num){
				cout << y << " " << x;
				return 0;
			}
		}
		t = (t + 1) % 4;
		x += dx[t];
		y += dy[t];
		a[x][y] = sc[++numa];
		if(sc[numa] == num){
			cout << y << " " << x;
			return 0;
		}
		suma = m;
		suma -= 1;
	}
	return 0;
}
