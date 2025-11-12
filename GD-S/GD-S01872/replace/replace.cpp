#include<bits/stdc++.h>
using namespace std;
struct node{
	string f, s;
}ss[200005];
int km[2005][2005];
int n, q, ans;
string x, y;
void kmp(int id, string kl){
	int len = kl.length(),j = -1;
	km[id][0] = -1;
	for(int i = 1;i < len;i++){
		while(j > -1 && kl[j + 1] != kl[i])j = km[id][j];
		if(kl[j + 1] == kl[i])j++;
		km[id][i] = j;
	}
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); 
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> ss[i].f >> ss[i].s;
		kmp(i << 1, ss[i].f);
		kmp(i << 1 | 1, ss[i].s); 
	}
	while(q--){
		ans = 0;
		cin >> x >> y;
		for(int i = 1;i <= n;i++){
			int l = x.length(), t = -1, tt = -1;
			for(int j = 0;j < l;j++){
				while(t > -1 && x[j] != ss[i].f[t + 1])t = km[i << 1][t];
				while(tt > -1 && y[j] != ss[i].s[tt + 1])tt = km[i << 1 | 1][tt];
				if(ss[i].f[t + 1] == x[j])t++;
				if(ss[i].s[tt + 1] == y[j])tt++;
				if((t == (int)(ss[i].f.length() - 1)) && (tt == (int)(ss[i].s.length() - 1))){
					string uu = x;
					for(int op = j - ss[i].f.length() + 1;op <= j;op++)
						uu[op] = ss[i].s[op - (j - ss[i].f.length() + 1)];
					if(uu == y)ans++;
				}
			}
		}
		cout << ans << '\n';
	} 
	return 0;
}

