#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e6 + 5;
const int M = 2e5 + 5;
const int Mod = 1e9 + 7;
namespace subtask1{
	ll H[N];
	void init(){
		H[0] = 1;
		for (int i = 1;i < N;++i) H[i] = H[i - 1] * 19260817 %Mod;
	}
	struct node{
		vector<ll> hs,ht;
		ll Hs,Ht; 
		string s,t;
		int L,R,len;
		void init(){
			s = ' ' + s;
			t = ' ' + t;
			len = s.size();
			L = 0,R = len;
			hs.clear(); ht.clear();
			for (int i = 1;i < len;++i){
				if (s[i] == t[i]) L = i;
				else break;
			}
			    
			for (int i = len - 1;i >= 1;--i){
			    if (s[i] == t[i]) R = i;
			    else break;
			}
			ll h = 0; hs.push_back(0);
			for (int i = 1;i < len;++i){
				h = h * 19260817 + (s[i] - 'a' + 1); h %= Mod;
				hs.push_back(h); 
			} Hs = h; h = 0; ht.push_back(0);
			for (int i = 1;i < len;++i){
				h = h * 19260817 + (t[i] - 'a' + 1); h %= Mod;
				ht.push_back(h);
			} Ht = h; 
		}
	}s[M],t;	
	ll query(ll L,ll R,ll len){
		return (R - L * H[len] % Mod + Mod) % Mod;
	}
	int n,q,cnt = 0;
	void main(){
		init();
		cin >> n >> q;
		
		for (int i = 1;i <= n;++i){
			cin >> s[i].s >> s[i].t;
			s[i].init();
			//if (mp.find(make_pair(s[cnt].Hs,s[cnt].Ht)) != mp.end()){--cnt;continue;}
		  //  mp[make_pair(s[cnt].Hs,s[cnt].Ht)] = 1;
		}
		
		for (int i = 1;i <= q;++i){
			cin >> t.s >> t.t;
			t.init();
			//cout << t.s << " " << t.t << " " << t.len << endl; 
			int ans = 0;
			for (int j = 1;j <= n;++j){
				if (s[j].L > t.L || s[j].R > t.R || s[j].len > t.len) continue;
				if (s[j].R - s[j].L != t.R - t.L) continue;
				if (s[j].L >= s[j].R) continue;
				int L = s[j].R - 1,R = s[j].len - s[j].L - 1;
				if (query(s[j].hs[s[j].L],s[j].hs[s[j].R - 1],s[j].R - s[j].L - 1) != 
					query(t.hs[t.L],t.hs[t.R - 1],t.R - t.L - 1)) continue;
				/*if (i == 1 && j == 3){
				    cout << L << "-" << R << " " << t.R << " " << endl;
				    cout << s[j].hs[L] << endl;
				    cout << query(0,s[j].hs[L],L) << " " << query(t.hs[t.R - L - 1],t.hs[t.R - 1],L) << endl;
				}*/
				if (t.R - L - 1 < 0 || t.L + R >= t.len) continue;
				assert(t.R - L - 1 >= 0);
				assert(t.L + R < t.len);
				if (query(0,s[j].hs[L],L) == query(t.hs[t.R - L - 1],t.hs[t.R - 1],L) && 
				    query(0,s[j].ht[L],L) == query(t.ht[t.R - L - 1],t.ht[t.R - 1],L) && 
					query(s[j].hs[s[j].L],s[j].Hs,R) == query(t.hs[t.L],t.hs[t.L + R],R) && 
					query(s[j].ht[s[j].L],s[j].Ht,R) == query(t.ht[t.L],t.ht[t.L + R],R))
					    ++ans;
			}
			cout << ans << '\n';
		}
		return ;
	}
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	subtask1 :: main();
	
	return 0;
} 
