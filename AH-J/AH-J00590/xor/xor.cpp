#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N=1e2+10;
int n,k,a[N],x,l=1,ans;

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i=1; i <= n; i ++){
		cin >> a[i];
		a[i]^=a[i-1];
	}
	for(int i=1; i <= n; i ++){
		for(int j=i; j >= l; j --){
			int x=a[i];
			int y=a[j-1];
			if(x^y == k){
				ans ++;
				l=j-1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
