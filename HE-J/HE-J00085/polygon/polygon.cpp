#include<bits/stdc++.h>
using namespace std;

long long ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=3;i<=n;i++){
		ans += n/i;
	}
	cout << ans % 998244353;
	
	return 0;
} 
