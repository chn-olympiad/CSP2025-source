#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n; 
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++){
		s[i] = a[i] + s[i-1];
	}
	for(int i = 3; i <= n-1; i++){
		for(int j = 1; j <= n-i; j++){
			int l = j;
			int r = j+i;
			int m = s[r] - s[l-1];
			for(int k = l; k < r;k++){
				if(m-a[k] > 2*a[r]){
					ans++;
				}
			}
			if(m-a[r] > 2 * a[r-1]) ans++;
		}
	}
	if(s[n]>2*a[n]) ans++;
	cout << ans;
	return 0;
}
