#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, q, b[200005], n[200005], bl, nl;
string s[2][200005], t[2];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> m >> q;
	for(int i=1; i<=m; i++){
		cin >> s[0][i] >> s[1][i];
		for(b[i]=0; b[i]<s[0][i].size()&&s[0][i][b[i]]=='a'; b[i]++);
		for(n[i]=0; n[i]<s[1][i].size()&&s[1][i][n[i]]=='a'; n[i]++);
	}
	for(int i=1; i<=q; i++){
		cin >> t[0] >> t[1]; int cnt=0;
		for(bl=0; bl<t[0].size()&&t[0][bl]=='a'; bl++);
		for(nl=0; nl<t[1].size()&&t[1][nl]=='a'; nl++);
		for(int j=1; j<=m; j++){
			if(b[j]-n[j]==bl-nl&&bl>b[j]&&nl>n[j]) cnt++;
		}
		if(t[0].size()!=t[1].size()) cnt=0;
		cout << cnt << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
