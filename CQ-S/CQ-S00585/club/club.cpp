#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int main(){
//	freopen("culb1.in","r",stdin);
//	freopen("culb1.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n;cin >> n;
		int ans = 0;
		int c[N],s[N],p[N];
		for(int i = 1;i <= n;i++){
			cin >> c[i] >> s[i] >> p[i];
		}
		sort(c + 1,c + 1 + n);
		sort(s + 1,s + 1 + n);
		for(int i = n;i > n / 2;i--){
			ans += c[i] + s[i];	
		}
		cout << ans;
	}

	return 0;
}

