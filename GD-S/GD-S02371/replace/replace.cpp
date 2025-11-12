#include<bits/stdc++.h>
using namespace std;
#define int long long

int ans = 0;
string a, b;

struct Rule{
	string a, b;
	Rule(string s1, string s2){
		a=s1, b=s2;
	}
};
const int N = 5e6;
vector<Rule> rule[N];

signed main(){
	ios::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, T;
	cin >> n >> T;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		rule[a.size()].emplace_back(Rule(a, b));
	}
	while(T--){
		ans = 0;
		cin >> a >> b;
		for(int i=0;i<a.size()-1;i++){
			for(int j=i+1;j<a.size();j++){
				string a_ = a;
				for(Rule r : rule[j-i+1]){
//					if(j-i+1==2) cout << r.a << ' ' << r.b;
					bool flag = 1;
					for(int c=i;c<=j;c++) {
//						if(j-i+1==2&&r.a=="bc")
//						 cout << r.a[c];
						if(a_[c]!=r.a[c-i]) {
							flag = 0;
							break;
						}
					}
					if(flag){
						a_.replace(i, j-i+1, r.b);
						if(a_==b) {
							ans++;
//							cout << r.a << ' ' << r.b << '\n';
						}
//						cout << r.a << ' ' << r.b;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
