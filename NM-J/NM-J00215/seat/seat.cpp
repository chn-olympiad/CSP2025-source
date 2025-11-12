#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,r;
	cin >> n >> m >> r;
	int s = n*m;
	int a[s+10];
	a[1] = r;
	for(int i = 2; i <= s-1; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= s; i++){
		for(int j = i + 1; j <= s ; j++){
			if(a[j] > a[i]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i = 1 ; i<= s; i++){
		if(a[i] == r) p = i;
	}
	int ans1 = ceil(p*1.00/n);
	cout << ans1 << " ";
	if(ans1 % 2 == 0) cout << n - p % n + 1;
	else cout << p % n;
	cout << endl;
	return 0;
}
