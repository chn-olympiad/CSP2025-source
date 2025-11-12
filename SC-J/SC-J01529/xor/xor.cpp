#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N];
long long s[N];
struct node {
	int l , r;
}k[N];
int q;
bool cmp(node x , node y){
	return x.r < y.r;
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n;
	long long w , ans = 1;
	cin >> n >> w;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == 1) s[i] = a[i];
		else s[i] = s[i - 1] ^ a[i];
	}
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= n - i + 1; j++){
			long long cnt = s[i + j - 1] ^ s[j - 1];
			if(cnt == w){
				k[++q].l = j;
				k[q].r = j + i - 1;
			}
		}
	}
	sort(k + 1 , k + q + 1 , cmp);
	int o = k[1].r;
	for(int i = 2; i <= q; i++){
		if(k[i].l > o) {
			o = k[i].r;
			ans++;
		}
	}
	cout << ans;
	return 0;
}