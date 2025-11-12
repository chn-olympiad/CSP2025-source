#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],num;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
		if(i == 1) num = a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int x = 1,y = 1,cnt = 0;
	while(1){
		cnt++;
		if(a[cnt]==num){
			cout << y <<' ' << x;
			break;
		}
		if(y % 2 == 1 && x != n){
			x++;
		}else if(y % 2 == 1 && x == n){
			y++;
		}else if(y % 2 == 0 && x != 1){
			x--;
		}else if(y % 2 == 0 && x == 1){
			y++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
