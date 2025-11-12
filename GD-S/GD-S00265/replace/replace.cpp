#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using LL = long long;

int n, q, tot;
string s[N][3];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		cin >> s[i][1] >> s[i][2];
	}
	
	for(int i = 1; i <= q; ++i){
		tot = 0;
		string t1, t2;
		cin >> t1 >> t2;
		
		for(int j = 1; j <= n; ++j){
			string k = "";
			
			if(t1.find(s[j][1]) < t1.size()){
				k = t1.substr(0, t1.find(s[j][1])) + s[j][2] + t1.substr(t1.find(s[j][1]) + s[j][1].size(), t1.size());
				
				if(k == t2) tot++;
			}
		}
		
		cout << tot << "\n";
	}
	
	
	return 0;
}
