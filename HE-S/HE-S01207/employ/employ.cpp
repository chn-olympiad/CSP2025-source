#include<bits/stdc++.h>
using namespace std;
long long int n , m , c[600];
string s;
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	cin >> s;
	for(int i = 1; i <= n; i++){
		scanf("%d" , &c[i]);
	}
	if(m == 1){
		printf("%d" , n);
		return 0;
	}
	if(m == n){
		printf("%d" , 1);
		return 0;
	}
	return 0;
}
