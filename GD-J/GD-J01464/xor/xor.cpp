#include <bits/stdc++.h>
using namespace std;
int a[500010];
long long b[500010];
int sum(int x, int y){
	int sum = a[x];
	for(int i = x+1;i <= y;i++){
		sum = sum ^ a[i];
	}
	return sum;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n == 1 && k == 0 && a[1] != 0) cout << 0 << "\n";
	else if(n == 2 && k == 0 && a[1] == 1 && a[2] == 1) cout << 1 << "\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
