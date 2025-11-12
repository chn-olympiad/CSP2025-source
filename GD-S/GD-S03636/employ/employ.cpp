#include <bits/stdc++.h>
using namespace std;
const int N = 505;
string a;
int b[N] , flag[N];
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	int n , m;
	scanf("%d%d" , &n , &m);
	cin >> a;
	for(int i = 1 ; i <= n ; i ++){
		cin >> b[i];
	}
	long long cnt = 0;
	sort(b + 1 , b + 1 + n);
	int c = b[1];
	for(int i = 1 ; i <= n ; i ++){
		if(flag[i] == 1) continue;
		if(b[i] >= c && flag[i] == 0){
			cnt ++;
			c = b[i];
			flag[i] = 1;
		}		
		for(int j = i + 1 ; j <= n ; j ++){
			if(b[j] <= b[i]){
				flag[j] = 1;
			}
		}
	}
	long long t = 1;
	for(int i = 1 ; i <= cnt ; i ++){
		t *= i;
	}
	t %= 998244353;
	printf("%lld" , t);
	return 0;
}
