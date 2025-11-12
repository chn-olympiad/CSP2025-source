#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int a1[100100];
		int n,x[100100],y[100100];
		cin >> n;
		for(int i = 0;i < n;i++){
			int a,b,c;
			cin >> a >> b >> c;
			x[i] = min(a,b);
			y[i] = a-b;
			a1[i] = a;
		}
		sort(a1,a1+n);
		int ans = 0;
		for(int i = n-1;i >= n-1-(n/2);i--){
			ans += a[i];
		}
		cout << ans << endl;
	}
	return 0;
}
