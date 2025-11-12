#include <bits/stdc++.h>
using namespace std;
int g[50005];
int a[50005];
//int dp(int n_1,int n_2){
//	int num = 0;
//	//±ß½çÌõ¼ş
//	if (n_2-n_1 <= 3){
//		return num;
//	}
//	if (a[n_1] >= g[n_2]-g[n_1+1]){
//		a[n_1] = 0;
//	}
//	else{
//		num += (n_2 - n_1 + 1);
//		dp(n_1-1,n_2);
//	}
//}
int f(int n){
	int k;
	for (int i = 1; i <= n; i ++){
		k *= n;
	}
	return k;
}
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++){
		int x;
		cin >> x;
		a[i] = x;
		g[i] = g[i-1] + x;
	}
	cout << rand()%f(n)+1;
	return 0 ;
}
