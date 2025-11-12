#include<bits/stdc++.h>
using namespace std;
int n, m, max_wait, pre0, num1, may;
int a[10005];
bool flag = true;
string s;
int pailie(int x){
	int sum = 1;
	for (int i = 1; i <= x; i++){
		sum *= i;
	}
	return sum;
}
int main(){
	freopen("empoly.in", "r", stdin);
	freopen("empoly.out", "w", stdout);
	int n, m;
	string s;
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		max_wait = max(max_wait, a[i]);
	}
	for (int i = 1; i <= n; i++){
		if (s[i] == '1'){
			num1++;
			may = i;
			flag = false;	
		}
		if(flag && s[i] == '0'){
			pre0++;
		}	
	}
	if(num1 == n){
		int ans = pailie(n);
		cout << pailie;
	}
	else if (m == 1 && max_wait > pre0){
		cout << pailie(n-1);
	}
	return 0;
}
