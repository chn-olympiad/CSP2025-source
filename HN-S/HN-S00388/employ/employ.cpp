#include<bits/stdc++.h>
using namespace std;
int maxn = 998244353;
int s[501], b[501], s1 = 0;
char k;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, a = 0, b1 = 0, k1 = 0;
	long long num = 1;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		cin >> k;
		s[i] = k - '0';
		if(s[i] == 1 && k1 == 0){
			k1 = i;
		}
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		if(b[i] <= k1){
			b1++;
		}
	}
	sort(b+1, b+n+1);
	if(m == 1){
		num = n - b1;
		for(int i = 2; i <= n; i++){
			num *= n-i+1;
			num = num % maxn;
		}
	}else{
		for(int i = 1; i <= n; i++){
			num *= n-i+1;
			num = num % maxn;
		}
	}
	cout << num;
//	for(int i = 1; i <= n; i++){
//		cin >> k;
//		if(k == '0'){
//			s1++;
//			s[s1] = a;
//			a = 1;
////			cout << i << " " << s1 << " " << s[s1] << endl;
//		}else{
//			a++;
//		}
//	}
//	s1++;
//	s[s1] = a;
//	for(int i = 1; i <= n; i++){
//		scanf("%d", &a);
//		b[a]++;
//	}
//	for(int i = 1; i <= s1; i++){
//		
//	}
	return 0;
}
