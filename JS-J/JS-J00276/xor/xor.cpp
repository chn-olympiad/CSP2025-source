#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long num[500005];
long long twzte(string x){
	int cnt = 0;
	long long ans = 0;
	for(int i = x.size() - 1; i >= 0; i--){
		ans = ans + (int)(x[i] - '0') * pow(2, cnt);
		cnt ++;
	}
	return ans;
}
string teztw(long long x) {
	string s;
	while(x != 0) {
		int tmp = x % 2;
		x /= 2;
		s = (char)(tmp +'0') + s;
	}
	return s;
}
string pd(string x, string y){
	if(x.size() < y.size()){
		swap(x, y);
	}
	string s;
	int len = y.size();
	int c = x.size() - len;
	int i = x.size();
	int j = y.size();
	for(; j >= 0; j--){
		if(x[i] == y[j])
			s = '0' + s;
		else 
			s = '1' + s;
		i--;
	}
	for(int l = 1; l <= c; l++)
		s = '1' + s;
	return s;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%lld", &n, &k);
	bool f = 0;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &num[i]);
		if(num[i] != num[1]){
			f = 1;
		}
	}
	if(f == 0){
		if(k == 0)
			printf("%d", n / 2);
		else
			printf("0");
		return 0;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		long long sum = num[i];
		if(twzte(teztw(sum)) == k){
			cnt++;
		}
		for(int j = i + 1; j < n; j++) {
			string x = teztw(num[j]);
			string y = teztw(sum);
			sum = twzte(pd(x, y));
			if(sum == k){
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
