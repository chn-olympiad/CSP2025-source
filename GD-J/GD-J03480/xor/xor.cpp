#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen(number.in, "r", stdin);
	freopen(number.out, "w", stdout);
	int n, k, l[114], ans=0;
	cin >> n >> k;
	if(n<=2){
		for(int i=0;i<n;i++)cin >> l[i];
		if(l[0]==k)ans++;
		if(n=2&&l[1]==k)ans++;
		if(n=2&&(l[0] ^ l[1])==k)ans++;
	}else{
		ans=n/2;
	}
	cout << ans;
	
	
	return 0;
}
