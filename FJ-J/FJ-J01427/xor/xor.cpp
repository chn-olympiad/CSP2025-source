#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin);\
				freopen(x".out","w",stdout)
const int N = 5e5+10;
int n,k,a[N],b[N],last=0,ans;
int main(){
	FILE("xor");
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i] = (b[i-1] ^ a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>last;j--){
			if((b[i] ^ b[j-1]) == k){
				last = i;
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}

