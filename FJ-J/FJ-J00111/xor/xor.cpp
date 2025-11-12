#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long ans;
int a[500005];
int s[500005];
int ml = 0,mr = 0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = a[i] ^ s[i-1];
		if(a[i] == k){
			ans++;
			if(i > ml) ml = i;
			if(i > mr) mr = i;
		}
	} 
	for(int i = 1;i <= n-1; i++){
		for(int j = 1; j <= n-i; j++){
			int l = j;
			int r = j+i;
			int x = s[r] ^ s[l-1];
			if(x == k && (r < ml || l > mr) ){
				ans++;
				if(r < ml) ml = r;
				else mr = l;  
			}
		}
	}
	cout << ans;
	return 0;
}
