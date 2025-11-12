#include<bits/stdc++.h>

using namespace std;

int n;
int a[5100];
int ans = 0;

void dfs(int x , int maxx , int k){
	if(x > maxx * 2){
		ans = (ans + 1) % 998244353;
	}
	for(int i = k + 1;i <= n;i++){
		dfs(x + a[i] , max(maxx , a[i]) , i);
	}
}

int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(0 , 0 , 0);
	cout << ans <<endl;
	
	return 0;
}
