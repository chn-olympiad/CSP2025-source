#include<bits/stdc++.h>
using namespace std;
int b[5555];
int n;
int cc = 0;
void dfs(int i , int sum , int maxn , int num){
	maxn = max(maxn , b[i]);
	sum += b[i];
	num ++;
	if (num >= 3 && sum > maxn * 2){
		cc ++;
	}
	for (int j = i + 1;j <= n;j ++){
		dfs(j , sum , maxn , num);
	}
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for (int i = 1;i <= n;i ++){
		cin >> b[i];
	}
	for (int i = 1;i <= n;i ++){
		dfs(i , 0 , 0 , 0);
	}
	cout << cc;
	return 0;
}