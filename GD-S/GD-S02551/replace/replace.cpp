#include <bits/stdc++.h>
using namespace std;

long long n, q;
string s[200005][2], t[200005][2];
bool tfb = 1;
long long l[200005], r[200005], m[200005];
void spe_b(){
	for(int i = 1;i <= n;i++){
		int id1 = 0, id2 = 0;
		for(int j = 0;j < s[i][0].size();j++)
			if(s[i][0][j] == 'b')
				id1 = j;
		for(int j = 0;j < s[i][1].size();j++)
			if(s[i][1][j] == 'b')
				id2 = j;
		l[i] = id1, r[i] = s[i][0].size() - id1, m[i] = id1 - id2;
	}
	for(int i = 1;i <= q;i++){
		int id1 = 0, id2 = 0;
		if(t[i][0].size() != t[i][1].size()){
			cout << 0 << endl;
			continue;
		}
		for(j = 0;j < t[i][0].size();j++)
			if(t[i][0][j] == 'b')
				id1 = j;
		for(j = 0;j < t[i][1].size();j++)
			if(t[i][1][j] == 'b')
				id2 = j;
		int dif = id1 - id2, tot = 0;
		for(int j = 1;j <= n;j++)
			if(l[i] <= id1 && r[i] <= t[i][0].size() - id1 && m[i] == dif)
				tot++;
		cout << tot << endl;
	}
	return ;
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s[i][0] >> s[i][1];
		for(int j = 0;j < s[i][0].size();j++)
			if(s[i][0][j] != 'a' && a[i][0][j] != 'b')
				tfb = 0;
	}
	for(int i = 1;i <= q;i++)
		cin >> t[i][0] >> t[i][1];
	if(tfb == 1){
		spe_b();
		return 0;
	}
	return 0;
}
