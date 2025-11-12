#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n,k,ans;
int a[N],d[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		d[i] = d[i - 1] ^ a[i];
	}
	int cnt = 0;
	for(int l = 1,r = 1;l <= n;l++){
		while(r <= n && ((d[r] ^ d[l - 1]) != k)) r++;
		if(r > n){
			r = l + 1;
			continue;
		}
		cnt++;
		l = r;
		r++;
	}
	ans = max(ans,cnt);
	cout << ans;
	return 0;
}