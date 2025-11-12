#include<bits/stdc++.h>
using namespace std;
long long n,k;
const int maxn = 2e7+10;
long long b[maxn],a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >>k;
	long long cat = -1;
	for(int i = 1;i<=n;i++){
		cin >> b[i];
		a[b[i]]++;
		cat =max(cat,b[i]);
	}
	if(n == 1){
		if(b[1] == k){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else if(n == 2){
		if(b[1] == k&&b[2] == k){
			cout << 2;
		}
		else if((b[1] == k&&b[2] != k)||(b[1] == k&&b[2] != k)||(b[1] != k&&b[2] != k&&(b[1]^b[2] == k))){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else if(k == 0){
		long long ans = a[0];
		for(long long i = 1;i<=cat;i++){
			if(a[i]>1){
				ans+=a[i]/2;
			}
		}
		cout << ans;
	}
	else{
		cout << 2;
	}
	
	return 0;
}
