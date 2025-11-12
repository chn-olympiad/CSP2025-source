#include <bits/stdc++.h>
using namespace std;
#define FILE_OPEN
const int maxn = 2e5 + 5;
set<pair<string , string>> se;
int main(){
	#ifdef FILE_OPEN
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	#endif
	// special test B
	cin.tie(0) , cout.tie(0) -> sync_with_stdio(0);
	int n , m;
	cin >> n >> m;
	for(int i = 1;  i <= n ; i ++){
		string s , s2;
		cin >> s >> s2;
		se.insert({s , s2});
	}
	
	for(int q = 1;  q <= m ; q ++){
		string h , h2;
		cin >> h >> h2;
		int cnt = 0;
		for(int i = 0 ; i < h.length() ; i ++){
			for(int j = 1 ; i + j - 1 < h.length() ; j ++){
				string sub = h.substr(i , j) , s2;
				int ed = h2.length() - (h.length() - i - j) - 1;
				// ab|ba|a
				//    ^ 2 len=2
				// ab|bba|f 6 - len
				for(int k = i ; k <= ed ; k ++)s2.push_back(h2[k]);
//				cout << sub << " " << s2 << "\n";
				if(se.find({sub , s2}) != se.end()){
					cnt ++;
					string hh ;
					for(int k = 0 ; k < i ; k ++)hh.push_back(h[k]);
					hh += s2;
					for(int k = i + j ; k < h.length() ; k ++)hh.push_back(h[k]);
					if(hh != h2)cnt --;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}

