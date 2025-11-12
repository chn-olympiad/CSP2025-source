#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<string , string> ma;

int n , q;

int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	
	cin >> n >> q;
	
	for(int i = 1 ; i <= n ; i ++){
		string s1 , s2;
		cin >> s1 >> s2;
		
		ma[s1] = s2;
	}
	
	for(int i = 1 ; i <= q ; i ++){
		string t1 , t2;
		cin >> t1 >> t2;
		
		if(ma[t1] == t2) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}
