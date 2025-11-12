#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 20;
const int M = 3e6 + 20;
int n,k;
int a[N],s[N],b[M],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		
	}
	for(int i = 0;i <= 2000000;i++){
		b[i] = -1;
	}
	s[0] = 0;
	b[k] = 0;
	int lst = -1;
	for(int i = 0;i <= n;i++) dp[i] = -1;
	for(int i = 1;i <= n;i++){
		s[i] = s[i-1] ^ a[i];
		//cout << lst << " " << b[s[i]] << '\n';
		if(b[s[i]] != -1 && b[s[i]] >= lst){
			dp[b[s[i]]] = i;
			lst = i;
		}
		b[s[i] ^ k] = i;
	}
	int cnt = 0;
	for(int i = 0;i < n;i++){
		//cout << dp[i] << '\n';
		if(dp[i] != -1) cnt++;
	}
	cout << cnt;
	return 0;
}
