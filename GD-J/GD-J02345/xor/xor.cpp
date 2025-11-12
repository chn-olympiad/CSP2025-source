#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;int a[200005];
int sum;bool zero,one;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];if(a[i] == 0)zero = 1;
		if(a[i] == 1){one = 1;sum++;}
	}
	if(zero && !one){
		if(k == 1)cout << "0";
		else cout << n;
	}
	else if(zero && one){
		if(k == 1)cout << sum;
		else{
			int cnt = 0;
			for(int i = 1;i <= n;i++){
				if(a[i] == 1)break;
				cnt++;
			}
			for(int i = n;i >= 1;i--){
				if(a[i] == 1)break;
				cnt++;
			}
			cout << cnt+sum/2;
		}
	}
	else if(!zero && one){
		if(k == 1)cout << n;
		else cout << n/2;
	}
	return 0;
} 
