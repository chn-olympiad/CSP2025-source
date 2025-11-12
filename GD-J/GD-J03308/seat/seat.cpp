#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int b = 0;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
		if(i == 1){
			b = a[i];
		}
	}
	sort(a + 1,a + n * m + 1,cmp);
	int s = 0;
	for(int i = 1; i <= n * m; i++){
		if(a[i] == b){
			s = i;
		}
	}
	int x = 0,y = 0;
	if(s % n != 0){
		y = 1 + s / n;
		x = s % n;
	}else{
		y = s / n;
		x = n;
	}
	if(y % 2 == 0){
		cout << y << " " << n + 1 - x;
	}else{
		cout << y << " " << x;
	}
	return 0;
} 
