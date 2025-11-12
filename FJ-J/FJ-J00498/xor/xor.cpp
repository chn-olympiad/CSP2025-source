#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 *5 + 100; 
ll num[MAXN] ;
int k,n;
int f[MAXN];
int a[MAXN];
void solve()
{
	cin >> n >>k;
	
	bool flag = true;
	bool flag1 = true;
	for(int i = 0;i<n;i++){
		scanf("%lld",&num[i]);
		if(num[i] != 1) flag = false;
	}
	if(flag){
		cout << n/2;
	}
	else{
		int ans = 0;
		a[0] = num[0];
		for(int i = 1;i<n;i++){
			a[i] = a[i-1] ^ num[i];
		}
		int l=0,r=0;
		while(l < n && r < n){
			int L;
			if(l != 0) L = a[r] ^ a[l-1];
			if(l == 0) L = a[r]; 
			 if(L == k){
				ans ++;
				l = r+1;
				r = l; 
			}
			else if(L > k){
				l++;
				if(r < l) r++;
			}
			else {
				r++;
			}
		}
		cout << ans;
	}
}

int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	solve();
	return 0;
}

