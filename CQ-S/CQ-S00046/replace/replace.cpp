#include <bits/stdc++.h>
using namespace std;
#define Mod 998244353
int n,q,len,l[210005],r[210005],ans;
char a[5100005],b[5100005],c[5100005],d[5100005],e[5100005],f[5100005];
string aaaa,bbbb;
bool vis[210005];
bool pd(){
	for(int i = 1;i <= len;++i) if(a[i] != e[i]) return 0;
	return 1;
}
void sou(int pq){
	if(pq == 2) return;
	if(pd()){
		++ans;
		return;
	}
	for(int i = 1;i <= n;++i){
		if(vis[i] == 1) continue;
		for(int j = 1;j + r[i] - l[i] <= len;++j){
			bool pppp = 1;
			for(int k = l[i];k <= r[i];++k){
				if(a[j+k-l[i]] != b[k]){
					pppp = 0;
					break;
				}
			}
			if(pppp == 0) continue;
			vis[i] = 1;
			for(int k = l[i];k <= r[i];++k) f[j+k-l[i]] = a[j+k-l[i]];
			for(int k = l[i];k <= r[i];++k) a[j+k-l[i]] = c[k];
			//for(int i = 1;i <= len;++i) cout << a[i];
			//cout << "\n\n";
			//continue;
			if(r[i] - l[i] + 1 == len) sou(pq+1);
			else sou(pq);
			vis[i] = 0;
			for(int k = l[i];k <= r[i];++k) a[j+k-l[i]] = f[j+k-l[i]];
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i = 0;i <= 5000000;++i) d[i] = '#';
	for(int i = 1;i <= n;++i){
		l[i] = r[i-1]+1;
		r[i] = l[i]-1;
		cin >> d;
		for(int j = 0;j <= 5000000 && d[j] != '#';++j) b[++r[i]] = d[j];
		cin >> d;
		for(int j = 0;j <= 5000000 && d[j] != '#';++j) c[l[i]+j] = d[j];
		for(int j = l[i];j <= r[i]+1;++j) d[j - l[i]] = '#';
	}
	for(int i = 1;i <= n;++i) --r[i];
	while(q--){
		ans = 0;
		cin >> aaaa >> bbbb;
		if(aaaa.length() != bbbb.length()){
			cout << 0 << "\n";
			continue;
		}
		if(aaaa.length() == bbbb.length() && aaaa.length() == 1){
			cout << 0 << "\n";
			continue;
		}
		len = aaaa.length();
		for(int i = 0;i < len;++i) a[i+1] = aaaa[i];
		for(int i = 0;i < len;++i) e[i+1] = bbbb[i];
		sou(0);
		cout << ans << "\n";
	}
	return 0;
}
