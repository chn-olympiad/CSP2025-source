#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 1e6;
int tr[N][27], n, q, fl[N], trt, rt[N], cnt[N];
int head[N], vi[N], ne[N], tot;
string s1, s2, s3;
vector <int> vt, vp;
void addedge(int u, int v){
	ne[++tot] = head[u], vi[tot] = v, head[u] = tot;
}
int add(int rtt, string s){
	int id = rtt;
	for(char ch : s){
		int k = ch - 'a';
		if(!tr[id][k])
			tr[id][k] = ++trt;
		id = tr[id][k];
	}
	return id;
}
queue <int> que;
void dfs(int x){
	for(int i = head[x]; i; i = ne[i]){
		int y = vi[i];
		cnt[y] += cnt[x];
		dfs(y);
	}
}
void bfs(int x){
	for(int i = 0; i < 27; i++){
		if(tr[x][i]){
			que.push(tr[x][i]);
			fl[tr[x][i]] = x;
		}
		else
			tr[x][i] = x;
	}
	while(!que.empty()){
		int u = que.front();
		que.pop();
//		if(x == 6)
//			cout << u << " " << cnt[u] << " " << fl[u] << "\n";
		addedge(fl[u], u);
		for(int i = 0; i < 27; i++){
			if(tr[u][i]){
				fl[tr[u][i]] = tr[fl[u]][i];
				que.push(tr[u][i]);
			}
			else
				tr[u][i] = tr[fl[u]][i];
		}
	}
	dfs(x);
}
int fp(int id, string a){
	if(id == -1)
		return -1;
	for(auto ch : a){
		int k = ch - 'a';
		if(!tr[id][k])
			return -1;
		id = tr[id][k];
	}
	return id;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1 >> s2;
		int k = s1.length();
		if(s1 != s2){
			int l = 0, r = k - 1;
			while(s1[l] == s2[l])
				l++;
			while(s1[r] == s2[r])
				r--;
			int id = add(0, s1.substr(l, r - l + 1));
			if(!rt[id])
				rt[id] = ++trt;
			id = add(rt[id], s2.substr(l, r - l + 1));
			if(!rt[id]){
				rt[id] = ++trt;
				vt.push_back(trt);
			}
//			cout << l << " " << r << " " << s1.substr(0, l) + (string)"{" + s1.substr(r + 1, k - r - 1) << "\n";
			cnt[add(rt[id], s1.substr(0, l) + (string)"{" + s1.substr(r + 1, k - r - 1))]++;
		}
	}
	for(int i : vt)
		bfs(i);
	while(q--){
		cin >> s1 >> s2;
		int k = s1.length(), l = 0, r = k - 1;
		while(s1[l] == s2[l])
			l++;
		while(s1[r] == s2[r])
			r--;
		int id = fp(0, s1.substr(l, r - l + 1));
		if(id == -1 || !rt[id]){
			cout << "0\n";
			continue;
		}
		id = fp(rt[id], s2.substr(l, r - l + 1));
		if(id == -1 || !rt[id]){
			cout << "0\n";
			continue;
		}
		s3 = s1.substr(0, l) + (string)"{" + s1.substr(r + 1, k - r - 1), id = rt[id];
//		cout << s3 << "\n";
		int sum = cnt[id];
		for(char ch : s3){
			int k = ch - 'a';
			sum += cnt[id = tr[id][k]];
		}
		cout << sum << "\n";
	}
}
