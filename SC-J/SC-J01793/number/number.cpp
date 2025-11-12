#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<char> v;
bool cmp(char x, char y) {
	return y < x; 
}
signed main() {
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0) ;
	string s; cin >> s;
	int n = s.size() ;
	for(int i = 0;i < n;i ++)  {
		if(s[i] >= '0' && s[i] <= '9')
			v.push_back(s[i]) ;
	}
//	for(int i= 0;i < n;i ++) cout << v[i] << " " ;
	sort(v.begin() ,v.end(),cmp) ; 
	for(int i= 0;i < v.size();i ++) cout << v[i] ;
	return 0;
}


//#Shang4Shan3Ruo6Shui4