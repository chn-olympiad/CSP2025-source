#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
// Sample Accepted!!
// Club Archive~~
using namespace std;
const int MAX_N = 2e5+10;
int t, n, ca, cb, cc, da[MAX_N], db[MAX_N], dc[MAX_N];
long long ans;
int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		ca = cb = ans = cc = 0;
		cin >> n;
		for(int i=1;i<=n;++i){	
			int a, b, c;
			cin >> a >> b >> c;
			if(a>=b&&a>=c){
				ans+=a;
				da[++ca] = max(-a+b, -a+c);
			}else if(b>=a&&b>=c){
				ans+=b;
				db[++cb] = max(-b+a, -b+c);
			}else{
				ans+=c;
				dc[++cc] = max(-c+a, -c+b);
			}
		}
		
		if(ca>n/2){
			sort(da+1, da+1+ca);
			while(ca>n/2){
				ans+=da[ca--];
			}
		}else if(cb>n/2){
			sort(db+1, db+1+cb);
			while(cb>n/2){
				ans+=db[cb--];
			}
		}else if(cc>n/2){
			sort(dc+1, dc+1+cc);
			while(cc>n/2){
				ans+=dc[cc--];
			}
		}
		cout << ans << endl;
	}
	
}
