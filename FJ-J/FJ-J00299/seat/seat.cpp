#include <bits/stdc++.h>
using namespace std;
int n,m,a[200],s,ans=1,l[11],b = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++) cin >> a[i];
	s = a[1];
	for(int i = 1;i<=n*m;i++){
		for(int j = i+1;j<=n*m;j++)
			if(a[i] < a[j]) swap(a[i],a[j]);
	}
	for(int i = 1;i<=m*n;i++){
		if(a[i] != s) ans++;
		else break;
	}
	for(int i = n;i>=1;i--){
		l[i] = b;
		b++;
	}
	if(ans <= n) cout << 1 << ' ' << ans;
	else if(ans <= 2*n) cout << 2 << ' ' << l[ans-n];
	else if(ans <= 3*n) cout << 3 << ' ' << ans-2*n;
	else if(ans <= 4*n) cout << 4 << ' ' << l[ans-3*n];
	else if(ans <= 5*n) cout << 5 << ' ' << ans-4*n;
	else if(ans <= 6*n) cout << 6 << ' ' << l[ans-5*n];
	else if(ans <= 7*n) cout << 7 << ' ' << ans-6*n;
	else if(ans <= 8*n) cout << 8 << ' ' << l[ans-7*n];
	else if(ans <= 9*n) cout << 9 << ' ' << ans-8*n;
	else if(ans <= 10*n) cout << 10 << ' ' << l[ans-9*n];
	return 0;
}
