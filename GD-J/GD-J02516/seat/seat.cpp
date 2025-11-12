#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[105];
int s[15][15];
int x,y;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++) cin >> a[i];
	r = a[1];
	sort(a+1,a+n*m+1,cmp);
	x = 1;
	y = 1;
	for (int i = 1;i <= n*m;i++){
		s[x][y] = a[i];
		if (s[x][y] == r){
			cout << y << " " << x;
			break;
		}
		if (y%2==1){
			if (x == n)
				y++;
			else
				x++;
		}
		else{
			if (x == 1)
				y++;
			else
				x--;
		}
	}
	return 0;
}
/*
10 7
6 87 5 4 3 2
1 7 8 9 10 11
12 18 17 16 15 14
13 19 20 21 22 40
50 83 84 85 86 88
89 90 91 92 93 94
95 96 97 98 99 100
31 32 32 33 34 35
43 49 60 51 41 39
53 59 70 71 62 48
*/
