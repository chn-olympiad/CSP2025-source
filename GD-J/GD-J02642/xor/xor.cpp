#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,d,e,l[2000005],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> a >> b;
	for(int i = 1; i <= a; i++){
		cin >> c;
		d ^= c;
		if((l[d ^ b] != 0 || (d ^ b) == 0) && l[d ^ b] + 1 > e){
			e = i;
			ans++;
		}
		l[d] = i;
	}
	cout << ans;
	return 0;
} 
