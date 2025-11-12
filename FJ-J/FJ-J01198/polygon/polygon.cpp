#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n, a[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) 
    	cin >> a[i];
    sort(a + 1, a + 1 + n);
	if(n < 3) {
	  cout << 0;
	  return 0;	
	}
	if(n == 3) {
		if(a[1] + a[2] > a[3]) {
		   cout << 1;
		   return 0;	
		}
		cout << 0;
		return 0;	
	}
	if(n == 4) {
	  if(a[1] + a[2] > a[3])
	    ans++;	
	  if(a[2] + a[3] > a[4])
	    ans++;
	  if(a[1] + a[3] > a[4])
	    ans++;
	  if(a[1] + a[2] > a[4])
	    ans++;
	  if(2 * a[4] < a[1] + a[2] + a[3] + a[4]) 
	    ans++;
	  cout << ans;
	  return 0;
	}
	return 0;
}

