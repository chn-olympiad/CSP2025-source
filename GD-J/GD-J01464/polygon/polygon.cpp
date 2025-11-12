#include <bits/stdc++.h>
using namespace std;
int a[5010];
int b[5010];
int maxn(int x, int y){
	int maxnum = 0;
	for(int i = x;i <= y;i++){
		if(a[i] > maxnum) maxnum = a[i];
	}
	return maxnum;
}
int sum(int x, int y){
	int sum = 0;
	for(int i = x;i <= y;i++){
		sum += a[i];
	}
	return sum;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n < 3) cout << 0 % 998244353 << "\n";
	else{
		int cnt = 0;
		int maxnum = maxn(1, n);
		int sum = 0;
		for(int i = 1;i <= n;i++){
			sum += a[i];
		}
		if(sum > maxnum*2) cnt++;
		cout << cnt % 998244353 << "\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
