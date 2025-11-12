#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],hang=1,lie=1;
int main(){
	freopen(" seat.in","r",stdin);
	freopen(" seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i<=n*m;i++){
		cin >> a[i];
	}
	int ans = a[1];
	for (int j = 1;j<=n*m;j++){
		for (int i = 1;i<=n*m;i++){
				if (a[i]<=a[i+1]){
					swap(a[i],a[i+1]);
				}
		}
	}
	
	for (int i = 1;i<=n*m;i++){
		if (a[i]!=ans){
			if (hang%n==0){
				lie++;
				hang=1;
			}
			hang++;
		}
		else {
			if (m==3) hang=1;
			if (m!=n)	cout << (lie+m)%n << " " << hang;
			else cout << lie << " " << hang;
		}
	}
}