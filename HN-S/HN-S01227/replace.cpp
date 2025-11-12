#include<bits/stdc++.h>
#define f(i , l , r) for(int i = l;i <= r;i ++)
#define d(i , l , r) for(int i = r;i >= l;i --)
#define lowbit(x) ((x)&-(x))
#define pii pair<int,int>
#define fi first 
#define sc second
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int N = 5e6 + 10;
int n , q;
struct edge{
	int u , v , nxt;
}e[N];
int head[N] , tot = 0;
void add(int u,int v){
	e[++tot] = {u , v , head[u]} , head[u] = tot;
} 
int fail[N] , ch[N][26] , cnt = 1 , dis[N] , flg[N];
void insert(string s){
	int n = s.size();
	s =  " " + s;
	int u = 1;
	f(i , 1 , n){
		if(!ch[u][s[i]-'a'])ch[u][s[i]-'a'] = ++cnt;
		u = ch[u][s[i]-'a'];
		dis[u] = i;
	}
	flg[u] ++;
	return ;
}
void build(){
	queue<int>q;
	fail[1] = 1;
	f(i , 0 , 25){
		if(ch[1][i]){
			fail[ch[1][i]] = 1;
			q.push(ch[1][i]);
		}
		else ch[1][i] = 1;
	}
	while(!q.empty()) {
		int u = q.front();q.pop();
		for(int i = 0 ; i < 26;i ++){
			int v = ch[u][i];
			if(v) fail[ch[u][i]] = ch[fail[u]][i] , q.push(v);
			else ch[u][i] = ch[fail[u]][i];
		}
	}
	f(i , 2 , cnt)add(fail[i] , i);
//	f(i , 2 , cnt)cout << fail[i] << " ";cout << "\n";
}
int f[N][25];
void dfs(int u){
//	cerr << u << "\n"; 
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].v;
		flg[v] += flg[u];
		dfs(v);
	}
}
void init(){
//	cerr << head[0] << "\n"; 
	dfs(1);
	f(i , 1 , cnt)f[i][0] = fail[i];
	f(j , 1 , 24){
		f(i , 1 , cnt){
			f[i][j] = f[f[i][j-1]][j-1];
		}
	}
}
int query(int u,int k){
	int now = flg[u];
	d(i , 0 , 24)if(dis[f[u][i]] >= k)u = f[u][i];
	return (dis[u] < k ? 0 : now - flg[f[u][0]]);
}
signed main(){
	fre("replace");
	cin >> n >> q;
	f(i , 1 , n){
		string s1 , s2 , str;
		cin >> s1 >> s2;
		str.resize(s1.size() * 2);
		f(j , 0 , s1.size() - 1)str[j * 2] = s1[j] , str[j * 2 + 1] = s2[j];
//			cout << str << "\n";
		insert(str);
	}
	build();
	init();
//	return 0;
//	f(i , 1 , cnt)cout << flg[i] << " ";cout << "\n"; 
//	f(i , 1 , cnt)cout << dis[i] << " ";cout << "\n"; 
	f(i , 1 , q){
		string s1 , s2 , str = "";
		cin >> s1 >> s2;
		str.resize(s1.size() * 2);
		f(j , 0 , s1.size() - 1)str[j * 2] = s1[j] , str[j * 2 + 1] = s2[j];
		int u = 1;
		int sim = -1 , t = str.size() - 1;
		long long ans = 0;
		while(str[t] == str[t-1])t -= 2;
		f(j , 0 , str.size() - 1){
			u = ch[u][str[j]-'a'];
			if(j & 1){
				if(str[j] == str[j-1] && sim == j - 2)sim = j;
				if(j >= t)ans += query(u , j - sim);
//				cout << sim << " " << (j + 1 >> 1) << " " << ans << "\n"; 
			}
		}
		cout << ans << "\n";
	}
}
/*
2 2
xabcx xadex
bc de
xabcx xadex
aaaa bbbb

*/
