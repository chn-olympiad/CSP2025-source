#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[405];
int book[25][25];
int r,id;
int x,y;
bool cmp(int x,int y){
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	sum = n*m;
	for(int i = 1;i <= sum;i ++)
		cin >> a[i];
	r = a[1];
	sort(a + 1,a + sum + 1,cmp);
	x = 1,y = 1;
	id = 1;
	while(true){
		while((x + 1 <= n || x == n)){
			book[x ++][y] = a[id ++];
			if(book[x-1][y] == r){
				cout << y << " " << x-1;
				return 0;
			}
		}
		x --;
		if(y + 1 <= m)
			book[x][++ y] = a[id ++];
		if(book[x][y] == r){
			cout << y << " " << x;
			return 0;
		}
		while(x - 1 >= 1 || x == 1){
			book[--x][y] = a[id ++];
			if(book[x+1][y] == r){
				cout << y << " " << x+1;
				return 0;
			}
		}
		x ++;
		if(y + 1 <= m)
			book[x][++ y] = a[id ++];
		if(book[x][y] == r){
			cout << y << " " << x;
			return 0;
		}
	}
	return 0;
}
/*
 *100 99 98 97 96 95 94 93 92
 *100 95 94
 *99 96
 *98 97
*/
