#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int x = n*m;
	for(int i = 1; i <= x; i++){
		cin >> a[i];
	}
	int sum = a[1];
	sort(a+1, a+1+x,cmp);
	int num = 0;
	for(int i = 1; i <= x; i++){
		if(a[i] == sum){
			num = i;
			break;
		}
	}
	int d = (num-1)/n+1;
	int u = num % n;
	if(u == 0){
		u = n;
	}
	if(d % 2 == 0){
		u = n-u+1;
	}
	cout << (num-1)/n+1 << ' ' << u;
	return 0;
}
