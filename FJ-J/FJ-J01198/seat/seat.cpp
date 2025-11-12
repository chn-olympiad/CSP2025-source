#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) 
       cin >> a[i];
	int p = a[1];
	sort(a + 1, a + 1 + n * m);
	for(int i = n * m; i >= 1; i--) {
		if(a[i] == p) {
			ans = n * m - i + 1;
			break;
		}
	} 
	if(ans % n > 0){
	cout << ans / n + 1<< " ";	
	    if((ans / n + 1) % 2 == 1) {
	   	  cout << ans % n;
	   	  return 0;
	    }
    cout << n + 1 - (ans % n);
    return 0;
	}
	  cout << ans / n << " ";

	   if((ans / n) % 2 == 1) {
	   	  cout << n;
	   	  return 0;
	   }
	   else{
	   	cout << 1;
		return 0;
	   }
	
	return 0;
}

