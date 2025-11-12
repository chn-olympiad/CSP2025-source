#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int n,k,l,r,cnt,ans,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	l = 1;
	r = 1;
	cnt = a[l];
	while(r <= n){
		if(cnt == k){
			l = r + 1;
			r++;
			cnt = a[l];
			ans++;
		}
		else{
			r++;
			cnt ^= a[r];
		}
	}
	cout << ans;
	return 0;
}
