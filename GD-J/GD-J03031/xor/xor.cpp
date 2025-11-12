#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
long long num[10000];
long long dp[10000][10000];
bool f[10000][10000];
int marken[100000];
int markensum = 0;
bool check(int j,int e){
	for(int i = 1; i <= markensum ; i++){
		if(marken[i]<=e&&marken[i]>=j){
			return false;
		}
	}
	return true;
}
long long yhh(long long a1,long long a2){
	string s1 = "";
	if(a1 == 0) s1+='0';

	while(a1 != 0){
		s1 += (a1 % 2 + '0');
		a1/=2;
	}
	string s2 = "";
	if(a2 == 0) s2+='0';
	while(a2 != 0){
		s2 +=( a2 %2 + '0');
		a2 /= 2;
	}
	int l1 = s1.size();
	int l2 = s2.size();
	int weishu = max(l1,l2);
	if(l1<l2){
		for(int i = 1;i <= l2-l1;i++){
			s1+='0';
		}
	}
	if(l1>l2){
		for(int i = 1;i <= l1-l2;i++){
			s2+='0';
		}
	}
	long long ans = 0;
	int dx = 1;
	for(int i = 2; i <= weishu;i++){
		dx*=2;
	}
	for(int i = weishu-1; i >= 0; i--){
		if(s1[i] != s2[i])
			ans+=dx;
		dx/=2;
	}
	return ans;
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int sum = 0; 
	for(int i = 1; i <= n ; i++){
		cin >> num[i];
		if(num[i] == k){
			sum ++;
			f[i][i] == 1;
		}
		dp[i][i] = num[i]; 
		marken[markensum++] = i;
	}
	
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= n-i+1 ; j++){
			int e =  j+i-1;
			for(int p = j; p <= e; p++){
				dp[j][e] = yhh(dp[j][p],dp[p+1][e]);
				if(dp[j][e] == k&&check(j,e)){
					sum++;
					f[j][e] = 1;
					dp[j][e] = k;
				}
			}
		}
	}
	cout<< sum;
	
	return 0;
}
