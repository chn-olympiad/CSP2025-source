#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int n , k;
int b[N] , o[N];
inline void read(int& x){
	x = 0;
	bool f = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		f = (c == '-');
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c & 15);
		c = getchar();
	}
	if(f) x = -x;
}
int ans;
inline void work(int len){
	int f = 0 , t = 0 , t1 = 0;
	for(int i = 1;i <= len;++ i)
	f ^= a[i] , t1 += o[i];
	if(f == k && t1 == 0){
		++ o[1];
		++ o[len];
		t1 += 2;
		++ ans;
	}
	for(int i = 2;i + len - 1 <= n;++ i){
		t += o[i - 1];
		t1 += o[i + len - 1];
		f ^= a[i + len - 1];
		f ^= a[i - 1];
		if(t1 - t == 0 && f == k){
			++ o[i];
			++ o[i + len - 1];
			t1 += 2;
			++ ans;
		}
	}
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	read(n) , read(k);
	int ans1 = 0 , ans2 = 0;
	for(int i = 1;i <= n;++ i){
		read(a[i]);
		if(!a[i]) ++ ans1;
		if(a[i] == 1) ++ ans2;
	}
	if(ans1 + ans2 == n){
		if(!k) cout << ans1;
		else cout << ans2;
		return 0;
	}
	for(int len = 1;len <= n;++ len)
	work(len);
	cout << ans;
	return 0;
}