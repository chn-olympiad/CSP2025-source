#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
const int M = 5e6+5;
int n,q;
struct node{
	int st,e;
	string df;
};
struct node2{
	string a, b;
	node bk;
}E[N];
node find(string sa, string sb){
	string res = "";
	int st = 0, e = sa.size()-1;;
	while(sa[st] == sb[st] && st < (int)sa.size()) st++;
	if(st >= (int)sa.size()) return {-1, -1, ""};
	while(sa[e] == sb[e]) e--;
	for(int i = st; i <= e; i++){
		if(sa[i] == sb[i]) res += '0';
		else res += '1';
	}
	return {st,e,res};
}
string s1,s2;
bool cmp(node2 a, node2 b){
	return a.bk.df < b.bk.df;
}
pair<int, int> find(string df){
	int st = 1,e = n;
	int l = 1, r = n;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(E[mid].bk.df < df){
			l = mid+1, st = mid;
		}else r = mid-1;
	}
	l = 1, r = n;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(E[mid].bk.df > df){
			r = mid-1, e = mid;
		}else l = mid+1;
	}
	//while(df < E[st].bk.df && st <= n) st++;
	//while(df > E[e].bk.df && e >= 1) e--;
	return {st, e};
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1 >> s2;
		E[i] = {s1, s2, find(s1, s2)};
	}
	sort(E+1, E+1+n, cmp);
	
	for(int i = 1; i <= q; i++){
		cin >> s1 >> s2;
		int ans = 0;
		node tmp = find(s1, s2);
		pair<int,int> se = find(tmp.df);
		for(int j = se.first; j <= se.second; j++){
			if(tmp.df != E[j].bk.df || tmp.df.size() < E[j].bk.df.size() || tmp.st-E[j].bk.st < 0) continue;
			
			int flag = 1;
			for(int k = tmp.st-E[j].bk.st, k2 = 0; k2 < (int)E[j].a.size(); k++, k2++){
				if((s1[k] != E[j].a[k2]) || (s2[k] != E[j].b[k2])){
					flag = 0;
					break;
				}
			}
			if(flag) ans++;
		}
		
		cout << ans << '\n';
	}
	return 0;
}
