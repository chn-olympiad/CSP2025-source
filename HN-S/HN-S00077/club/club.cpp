#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		int n,ans = 0;
		cin >> n;
		for(int j = 1;j <= n;j++){
			int a,b,c,maxx;
			cin >> a >> b >> c;
			if(a > b && a > c) ans += a;
			else if(a < b && b > c) ans += b;
			else if(a < c && a < c) ans += c;
		}
		cout << ans << endl;
	}
	return 0;
}
//3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0
