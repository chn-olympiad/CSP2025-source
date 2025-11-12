#include <bits/stdc++.h>
using namespace std;

const int N = 5000;

int n;
bool ycx;
long long cnt;
long long a[N] , b[N];//b : xia biao

void f(int x, int m){//x : di x ceng xun huan m: mu biao ceng shu
	if(x > m){
		long long sum=0, maxn=0;
		for(int i=1;i<=m;i++){// get sum
			sum += a[ b[i] ];
			maxn = max(maxn, a[ b[i] ]);
		}
		if(sum > maxn*2) cnt++;
		cnt = cnt%998244353;
	}else{
		for(b[x] = b[x-1]+1;b[x] <= n;b[x]++){
			f(x+1, m);
		}
	}
}

int main(){
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1) ycx = 1;
	}
	if(ycx == 1){
		for(int m=3;m<=n;m++){
			f(1,m);
		}
		cnt = cnt%998244353;
		cout << cnt;
	}else{//all numbers are 1
		long long ans=0;
		for(int i=n-2;i>=1;i--){
			ans += i;
			ans = ans%998244353;
		}
		cout << ans;
	}
	
	return 0;
	}
