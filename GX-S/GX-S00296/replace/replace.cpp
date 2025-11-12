#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n , q;
map<int , bool> mp;
struct node{
	string x , y;
	int len;
}s[N];
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; ++i){
		cin >> s[i].x >> s[i].y;
		s[i].len = s[i].x.size();
		mp[s[i].len] = true;
	}
	sort(s + 1 , s + n + 1 , [](const node& p , const node& q){return p.len < q.len;});
	while(q--){
		int res = 0; int p = 1;
		string cur , mis;
		cin >> cur >> mis;
		for(int i = s[1].len ; i <= s[n].len ; ++i){
			if(!mp[i]) continue;
			int l = cur.size();
			if(i > l) break;
			
			for(int j = 0 ; j < l - i + 1; ++j){
				string s1 = "" , s2 = "";
				for(int k = j ; k < j + i; ++k){
					s1 += cur[k];
					s2 += mis[k];
				}
				string d1 = "" , d2 = "";
				for(int k = 0 ; k < l ; ++k){
					if(k >= j && k < j + i) continue;
					d1 += cur[k];
					d2 += mis[k];
				}
				if(d1 != d2) continue;
				while(p <= n){
					if(s[p].len > i) break;
					if(s1 == s[p].x && s2 == s[p].y) res++;
					++p;
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}

