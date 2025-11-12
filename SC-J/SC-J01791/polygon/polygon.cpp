#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[5010];
int s[5010];
bool f(int n){
	sort(s + 1 , s + 1 + n);
	long long sum = 0;
	for(int i = 1; i <= n - 1; i++){
		sum += s[i];
	}
	if(sum > s[n]){
		return true;
	}
	return false;
}
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 +n);
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			s[j] = 0;
		}
		for(int j = 1; j <= n; j++){
			s[j] = a[j];
			if(f(j) == true){
				cnt++;
				cnt %= 998;
				cnt %= 244;
				cnt %= 353;
			}
		}
	}
	cout << cnt - 1;
	return 0;
}