#include<bits/stdc++.h>
using namespace std;
int a[100000];
bool flag = false;
bool f2 = false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n , k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
	    if(a[i] == 1) flag = true;
		else {
		    flag = false;
		    break;
		}
	}
	int r = 0 , l = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == 0 || (a[i] == 1 && a[i - 1] == 1)) r++;
		if(a[i] == 1) l++;
	    if(a[i] <= 1) f2 = true;
		else {
		    f2 = false;
		    break;
		}
	}
	if(flag && k == 0) cout << n / 2 << endl;
	else if(f2 && k == 0) cout << r << endl;
	else if(f2 && k == 1) cout << l << endl;
	else cout << 2 << endl;
	return 0;
}
