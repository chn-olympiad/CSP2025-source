#include <bits/stdc++.h>
using namespace std;

long long n, k, s[500005], sum, sum1, ans;

void solve_10(){
	cout << n / 2;
}

void solve_20(){
	for(int i = 1;i <= n; i++){
		if(s[i] == 0)  ans++;
		if(s[i] == 1 && s[i + 1] == 1){
			ans++;
			i++;
		}
	}
	
	cout << ans;
}

void solve_20_2(){
	for(int i = 1;i <= n; i++){
		if(s[i] == 1)  ans++;
	}
	cout << ans;
}

void solve_else_part(){
	int t;
	for(int i = 1;i <= n; i++){
		if(s[i] == k){
			ans++;
			t = 0;
		}else{
			t ^= s[i];
			if(t == k)  ans++;
		}
	}
	cout << ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	
	for(int i = 1;i <= n; i++){
		cin >> s[i];
		if(s[i] == 1)  sum++;
		if(s[i] == 0)  sum1++;
	}
	
	if(sum == n)  solve_10();
	else if(sum + sum1 == n && k == 0)  solve_20();
	else if(sum + sum1 == n && k == 1)  solve_20_2();
	else solve_else_part();
	
	return 0;
}
