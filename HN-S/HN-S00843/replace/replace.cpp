#include <bits/stdc++.h>
#define cin fin
#define cout fout
#define endl '\n'
using namespace std;
ifstream fin("replace.in");
ofstream fout("replace.out");
string s[200010][10];
int main(){
	int n,q;
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
		cin >> s[i][1] >> s[i][2];
	while (q--){
		string t1,t2;
		cin >> t1 >> t2;
		long long ans = 0;
		for (int i = 1;i <= n;i++){
			int pre = 0;
			while (t1.find(s[i][1],pre) != t1.npos){
				int pos = t1.find(s[i][1],pre);
				for (int j = 0;j < (int)t1.size();j++){
					if ((j < pos || j >= pos + (int)s[i][1].size()) && t1[j] != t2[j])
						goto loop;
					if (j >= pos && j < pos + (int)s[i][1].size() && s[i][2][j - pos] != t2[j])
						goto loop;
				}
				ans++;
				loop:;
				pre = pos + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
