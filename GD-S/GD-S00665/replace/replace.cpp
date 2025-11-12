#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e3 + 10;
int n,q,sum;
string a[N],b[N],x,y;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
	for (int i = 1;i <= q;i++){
		cin >> x >> y;
		sum = 0;
		int ans1 = 0,ans2 = 0;
		for (int j = 1;j <= n;j++){
			for (int l = 0;l < x.size() - a[j].size() + 1;l++){
//				cout << '[' << l << "]\n";
				int chk = 1;
//				cout << a[j] << ' ' << &(x[l]) << '\n';
				for (int o = 0;o < a[j].size();o++){
					if (a[j][o] != x[o + l]){
//						cout << a[j][o] << ' ' << x[o + l] << '\n';
						chk = 0;
						break;
					}
				}
				if (chk){
//					cout << l;
					ans1 = 1;
					break;
				}
			}
			for (int l = 0;l < y.size() - b[j].size() + 1;l++){
				int chk = 1;
				for (int o = 0;o < b[j].size();o++){
					if (b[j][o] != y[o + l]){
						chk = 0;
						break;
					}
				}
				if (chk){
//					cout << l;
					ans2 = 1;
					break;
				}
			}
//			int chkabl = a.length(),chk = b.length();
//			for (int i = 1;i <= max(a.length(),b.length());i++){
//				if (a[i] != b[i]){
//					chkabl = i;
//				}
//			}
//			for (int i = 1;i <= n;i++){
//				if (a[i] != b[i]){
//					chkabr = i;
//				}
//			}
			if (ans1 && ans2)++sum;
		}
		cout << sum << '\n';
	}
	return 0;
}

