#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
string la[N];
string lb[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++){
		cin >> la[i] >> lb[i];
		la[i] = ' ' + la[i];
		lb[i] = ' ' + lb[i];
//		cout << la[i] << endl;
	}
	while (q--){
		string sa, sb;
		cin >> sa >> sb;
		sa = ' ' + sa;
		sb = ' ' + sb;
		string now;
		int ans = 0;
		for (int i = 1; i <= n; i++){
			int len = la[i].size()-1;
			int lz = sa.size()-1;
			for (int j = 1; j <= lz-len+1; j++){
//				cout << j << '/' << lz-len+1 << endl;
				now = sa;
				if (now.substr(j, len) != la[i].substr(1)){
					continue;
				}
				string x, y, z;
				if (j-1 >= 1){
					x = now.substr(1, j-1);
				}else{
					x = "";
				}
				
				y = lb[i].substr(1);
				if (lz-j-len+1 >= 1){
//					cout << lz << j << len << endl;
					z = now.substr(j+len);
				}else{
					z = "";
				}
				
				now = x+y+z;
//				cout << x << ' ' << y << ' ' << z << '/' << lz-j-len+1 <<endl;
//				cout << "?????" << x << '/' << y << '/' << z << endl;
				
				if (now == sb.substr(1)){
					ans++;
				}
			}
		}
		
		cout << ans << endl;
	}
	
} 


