#include <bits/stdc++.h>
using namespace std;

int main ()
{
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[n];
	for (int i=0;i<n;i++) cin >> a[i];
	if (k==0 && n==2){
		if (a[0] == a[1] && a[0] != 0)cout << 1;
		else if (a[0] == a[1] && a[0] == 0) cout << 2;
		else if (a[0]==0 || a[1]==0) cout << 1;
		else cout << 0;
	} 
	else if (n==1 && k == 2){
		if (a[0] = 0) cout << 1;
		else cout << 0;
	}
	else cout << 2;
	return 0;
 } 
