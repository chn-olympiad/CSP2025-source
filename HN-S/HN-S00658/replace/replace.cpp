#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
const int M = 5e6 + 10;
const int mod = 1e9 + 9;
struct node{
	int x,y,l;
}v[N];
map<int , int>mp;
int l,r,cnt = 0,w[N << 1],num = 0;
string m;
namespace trie{
		struct T{
			int son[28];
			vector<int>v;
		}s1[M],s2[M];
		inline void insert1(int t , int l , int k){
			if(l == 0){
				s1[t].v.push_back(k);
				return ;
			}
			l --;
			int x = m[l] - 'a' + 1;
			if(!s1[t].son[x]){
				s1[t].son[x] = ++ num;
			}
			t = s1[t].son[x];
			insert1(t , l , k);
		}
		inline void insert2(int t , int r , int k){
			if(r == m.size() - 1){
				s2[t].v.push_back(k);
				return ;
			}
			r ++;
			int x = m[r] - 'a' + 1;
			if(!s2[t].son[x]){
				s2[t].son[x] = ++ num;
			}
			t = s2[t].son[x];
			insert2(t , r , k);
		} 
		inline void ask1(int t , int l){
			for(int i = 0;i < s1[t].v.size();i ++){
				w[++ cnt] = s1[t].v[i];
			}
			if(l == 0)return ;
			l --;
			int x = m[l] - 'a' + 1;
			if(!s1[t].son[x])return ;
			t = s1[t].son[x];
			ask1(t , l);
		}
		inline void ask2(int t , int r){
			for(int i = 0;i < s2[t].v.size();i ++){
				w[++ cnt] = s2[t].v[i];
			}
			if(r == m.size() - 1)return ;
			r ++;
			int x = m[r] - 'a' + 1;
			if(!s2[t].son[x])return ;
			t = s2[t].son[x];
			ask2(t , r);
		}
};
inline int Mod(int x){
	return (x % mod + mod) % mod;
}
inline int to(node p){
	return Mod(p.x * p.y % mod * p.l);
}
inline node find(string s1 , string s2){
	node p;
	int a = -1,b = -1,sum1 = 0,sum2 = 0;
	for(int j = 0;j < s1.size();j ++){
		if(s1[j] != s2[j]){
			if(a == -1)a = j;
			b = j;
		}
	}
	l = a,r = b;
	for(int j = a;j <= b;j ++){
		sum1 = Mod(sum1 * 30 + (s1[j] - 'a' + 1));
		sum2 = Mod(sum2 * 30 + (s2[j] - 'a' + 1));
	}
	p = (node){sum1 , sum2 , b - a};
	return p;
}
inline bool check(node u , node v){
	if(u.x == v.x && u.y == v.y && u.l == v.l)return true;
	return false;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q,sum1 = 0,sum2 = 0,Num = 0;
	cin >> n >> q;
	for(int i = 1;i <= n;i ++){
		string s1,s2;
		cin >> s1 >> s2;
		if(s1 == s2)continue;
		v[i] = find(s1 , s2);
		if(!mp[to(v[i])]){
			mp[to(v[i])] = ++ num;
		}
		int t = mp[to(v[i])];
		sum1 += s1.size();
		sum1 += s2.size();
		m = s1;
		trie::insert1(t , l , i);
		m = s2;
		trie::insert2(t , r , i);
	}
	for(int i = 1;i <= q;i ++){
		string x,y;
		cin >> x >> y;
		sum2 += x.size();
		sum2 += y.size();
		node p = find(x , y);
		int t = mp[to(p)];
		if(!t){
			cout << "0" << "\n";
			continue;
		}
		cnt = 0;
		m = x;
		trie::ask1(t , l);
		m = y;
		trie::ask2(t , r);
		sort(w + 1 ,w + cnt + 1);
		int ans = 0;
		for(int j = 1;j <= cnt;j ++){
			if(j > 1 && w[j] == w[j - 1] && check(p , v[w[j]])){
				++ ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
