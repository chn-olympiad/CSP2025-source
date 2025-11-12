#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n, k, ans = 1, h;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
	}
    int q = a[1];
      for(int i = 2; i <= n; i++) {
	  if(q == k) {
      		ans++;
      		q = a[i];
		}
      	q = (q^a[i]);
	}	
    cout << ans; 
	return 0;
}

