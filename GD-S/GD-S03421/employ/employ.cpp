#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	
	scanf("%d%d", &n, &m);
	
//	if(m == 1){
		char S[505];
		int s[505];
		int q[505];
		int cnt = 0;
		scanf("%c", &S[0]);
		for(int i = 1; i <= n; i++){
			scanf("%c", &S[i]);
//			if(S[i] == '0') s[i] = 0;
//			else s[i] = 1;
			if(S[i] == '1') cnt ++;
		}
//		int loc = 0;
//		for(int i = 1; i <= n; i++){
//			if(s[i] == 1){
//				loc = i;
//				break;
//			}
//		}
//		for(int i = 1; i <= n; i++){
//			scanf("%d", q[i]);
//			if(q[i] >= )
//		}
//		printf("")
//		return 0;
//	}
	if(cnt < m) printf("0");
	else{
		long long ans = 1;
		
		for(int i = 1; i <= n; i++){
			ans *= i;
			ans %= mod;
		}
		
		printf("%lld", ans);
	}
	
	
	
	return 0;
}
