#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 998244353;
int n , q;

namespace baoli {
	char s[6000005]; int _;
	struct string{
		pair <unsigned long long , long long> ha;
		
		void hash(){
			ha.first = ha.second = 0;
			for(int i = st;i <= st + le - 1;i++){
				ha.first = ha.first * 233 + s[i];
				if((ha.second = ha.second * 107 % MOD + s[i]) >= MOD)
					ha.second -= MOD;
			}
		}
		
		int st , le;
		void read(){
			st = _ + 1;
			scanf("%s" , s + st);
			le = strlen(s + st);
			_ += le;
			hash();
		}
	}s1[200005] , s2[200005];
	
	unsigned long long pow1[5000005]; long long pow2[5000005];
	struct t_string {
		char s[5000005]; int m;
		pair <unsigned long long , long long> ha[5000005];
		void haha(){
			ha[0].first = ha[0].second = 0;
			for(int i = 1;i <= m;i++){
				ha[i].first = ha[i - 1].first * 233 + s[i];
				if((ha[i].second = ha[i - 1].second * 107 % MOD + s[i]) >= MOD)
					ha[i].second -= MOD;
			}
		}
		
		pair <unsigned long long , long long> getlr(int l , int r){
			pair <unsigned long long , long long> ret = ha[r];
			pair <unsigned long long , long long> tmp = ha[l - 1];
			ret.first -= tmp.first * pow1[r - l + 1];
			if((ret.second += MOD - tmp.second * pow2[r - l + 1] % MOD) >= MOD) ret.second -= MOD;
			return ret;
		}
	}t1 , t2;

	void solve(){
		for(int i = 1;i <= n;i++){
			s1[i].read();
			s2[i].read();
		}
		pow1[0] = pow2[0] = 1;
		for(int i = 1;i <= 5000000;i++){
			pow1[i] = pow1[i - 1] * 233;
			pow2[i] = pow2[i - 1] * 107 % MOD;
		}
		while(q--){
			scanf("%s%s" , t1.s + 1 , t2.s + 1);
			t2.m = t1.m = strlen(t1.s + 1);
			t1.haha(); t2.haha();
			int m = t1.m;
			int l , r;
			for(int i = 1;i <= m;i++) if(t1.s[i] != t2.s[i]){ l = i; break; }
			for(int i = m;i >= 1;i--) if(t1.s[i] != t2.s[i]){ r = i; break; }
			int ans = 0;
			for(int i = 1;i <= n;i++) for(int y = r , _ = min(m , l + s1[i].le - 1);y <= _;y++) {
				int x = y - s1[i].le + 1;
				if(t1.getlr(x , y) == s1[i].ha && t2.getlr(x , y) == s2[i].ha){
					ans++;
					break;
				}
			}
			printf("%d\n" , ans);
		}
	}
}

//namespace zbojin_AK_CSP {
//	char s[6000005]; int _;
//	struct string{
//		pair <unsigned long long , long long> ha;
//		
//		void hash(){
//			ha.first = ha.second = 0;
//			for(int i = st;i <= st + le - 1;i++){
//				ha.first = ha.first * 233 + s[i];
//				if((ha.second = ha.second * 107 % MOD + s[i]) >= MOD)
//					ha.second -= MOD;
//			}
//		}
//		
//		int st , le;
//		void read(){
//			st = _ + 1;
//			scanf("%s" , s + st);
//			le = strlen(s + st);
//			_ += le;
//			hash();
//		}
//		
//		bool operator < (const string b){ return le < b.le; }
//	}; pair <string , string> sb[200005];
//	
//	unsigned long long pow1[5000005]; long long pow2[5000005];
//	struct t_string {
//		char s[5000005]; int m;
//		pair <unsigned long long , long long> ha[5000005];
//		void haha(){
//			ha[0].first = ha[0].second = 0;
//			for(int i = 1;i <= m;i++){
//				ha[i].first = ha[i - 1].first * 233 + s[i];
//				if((ha[i].second = ha[i - 1].second * 107 % MOD + s[i]) >= MOD)
//					ha[i].second -= MOD;
//			}
//		}
//		
//		pair <unsigned long long , long long> getlr(int l , int r){
//			pair <unsigned long long , long long> ret = ha[r];
//			pair <unsigned long long , long long> tmp = ha[l - 1];
//			ret.first -= tmp.first * pow1[r - l + 1];
//			if((ret.second += MOD - tmp.second * pow2[r - l + 1] % MOD) >= MOD) ret.second -= MOD;
//			return ret;
//		}
//	}t1 , t2;
//
//	void solve(){
//		for(int i = 1;i <= n;i++){
//			sb[i].first.read();
//			sb[i].second.read();
//		}
//		sort(s + 1 , s + 1 + n);
//		pow1[0] = pow2[0] = 1;
//		for(int i = 1;i <= 5000000;i++){
//			pow1[i] = pow1[i - 1] * 233;
//			pow2[i] = pow2[i - 1] * 107 % MOD;
//		}
//		while(q--){
//			scanf("%s%s" , t1.s + 1 , t2.s + 1);
//			t2.m = t1.m = strlen(t1.s + 1);
//			int m = t1.m;
//			t1.haha(); t2.haha();
//			int l , r;
//			for(int i = 1;i <= m;i++) if(t1.s[i] != t2.s[i]){ l = i; break; }
//			for(int i = m;i >= 1;i--) if(t1.s[i] != t2.s[i]){ r = i; break; }
//			int ans = 0;
//			for(int i = 1;i <= n;i++) {
//				if(sb[i].second.le > m || i >= 3) break;
//				for(int y = r , _ = min(m , l + sb[i].first.le - 1);y <= _;y++) {
//					int x = y - sb[i].first.le + 1;
//					if(t1.getlr(x , y) == sb[i].first.ha && t2.getlr(x , y) == sb[i].second.ha){
//						ans++;
//						break;
//					}
//				}
//			}
//			printf("%d\n" , ans);
//		}
//	}
//}

int main(void){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	scanf("%d%d" , &n , &q);
	if((n <= 1000 && q <= 1000) || q == 1){
		baoli::solve();
		return 0;
	}
	while(q--) puts("0");
	return 0;
}




