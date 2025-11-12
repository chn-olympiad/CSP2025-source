#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int my = a[1];
	sort(a+1, a+1+n*m, cmp);
	for(int i = 1; i <= n*m; i++){
		if(a[i] == my){
			my = i;
			break;
		}
	}
	if(my%n == 0){
		cout << my/n << " ";
		if((my/n)%2 == 0){
			cout << 1;
		}else{
			cout << n;
		}
		return 0;
	}
	cout << (my/n)+1 << " ";
	int tmp = (my/n)+1;
	my = my%n;
	if(tmp%2 == 1){
		cout << my;
		return 0;
	}
	cout << n-my+1;
	return 0;
}
