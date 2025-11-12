#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 200010;
int n,m;
string s1[MAXN],s2[MAXN];
string q1,q2;
int tj(){
	int cnt = 0;
	string s;
	for(int i = 1; i <= n; i++){
		s = q1;
		for(int j = 0; j < q1.length(); j++){
			if(q1[j] == s1[i][0]){
				bool bj = 1;
				for(int p = j; p < j + s1[i].length(); p++){
					if(q1[p] != s1[i][p - j]){
						bj = 0;
						break;
					}
				}
				if(bj){
					for(int p = j; p < j + s1[i].length(); p++) 
						s[p] = s2[i][p - j];
					break;
				}
			}
		}
		if(s == q2) cnt++;
	}
	return cnt;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
	}
	while(m--){
		cin >> q1 >> q2;
		cout << tj() << endl;
	}
	return 0;
}

