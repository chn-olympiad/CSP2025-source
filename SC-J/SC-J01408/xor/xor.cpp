#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 5e5 + 10;
long long  n, a[N], k, sum[N];
bool flag = true;
struct node{
	int b, e;
}b[N];
long long  t, ans;


bool cmp(node x, node y){
	return x.e < y.e;
}
int check(int l, int r){
	int s = a[l];
	for(int i = l+ 1;i <= r;i++){
		s ^= a[i];
	}
	return s;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i =1 ;i <= n;i++) {
		cin >> a[i];
		if(i > 1)sum[i] = sum[i-1]^a[i];
		if(a[i] != 1) flag = false;
	}
	sum[1] = a[1];
	if(flag){
		for(int len = 2;len <= n;len += 2){
			ans += n - len + 1;
		} 
		cout << ans << endl;
	}
	else {
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i ;j <= n;j++){
				if(check(i, j) == k){
					b[++cnt].b = i;
					b[cnt].e = j;
				}
			}
		}
		sort(b + 1, b + cnt + 1, cmp);
		t = b[1].e;	
		ans = 1;
		for(int i = 2;i <= cnt;i++){
			if(b[i].b <= t) continue;
			ans++;
			t = b[i].e;
		}
		cout << ans << endl;
	}
	return 0;
}