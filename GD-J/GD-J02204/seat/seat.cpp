#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int c,int b){
	if(c > b){
		return 1;
	}
	return 0;
}
void f(int u){
	int x = u % 2 * n,y = u / n + 1;
	if(x < n){
		cout << y << ' ' << x + 1;
	}else{
		cout << y << ' ' << 2 * n - x;
	}
	return;
}
int main(){
	cin >> n >> m;
	int x = n * m;
	for(int i = 1;i <= x;i++){
		cin >> a[i];
	}
	int u = a[0];
	sort(a,a + x,cmp);
	for(int i = 1;i <= x;i++){
		if(u == a[i]){
			f(i);
			break;
		}
	}
	return 0;
}
