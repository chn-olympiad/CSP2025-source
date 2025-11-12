#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

const long long int OICODE = 998244353;

long long int n,ans;
int mg[5005];
bool cmp(int a,int b){
	return a > b;
}

long long int jc(int n,int m){
	long long int h = 1;
	for(int i = n;i <= m;i++){
		h *= i;
	}
	return h;
	
} 
long long int sum(int n,int k){
	long long h1 = jc(1,k);
	long long h2 = jc(n - k + 1,n);
	return int(h2 / h1);
	
	
	
}








int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> mg[i];
	}
	sort(mg + 1,mg + n + 1,cmp);
	int maxa = mg[1];
	if(n == 3){
		if(mg[1] + mg[2] > mg[3] && mg[1] + mg[3] > mg[2] && mg[2] + mg[3] > mg[1]) cout << 1;
		else cout << 0;
		
	}
	else if(maxa == 1){
		for(int i = 3;i <= n;i++){
			ans = (ans + sum(n,i)) % OICODE;
		}
		cout << ans;
	}
	else cout << 0;
	
	
	
	return 0;
} 
