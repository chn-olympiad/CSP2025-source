#include<bits/stdc++.h>
using namespace std;
int n, q;
int cd[200005];
string ss[200005][2];


int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> ss[i][1] >> ss[i][2];
		cd[i] = ss[i][1].size()-1;
	}
	while(q--){
		int ans = 0;
		string s1, s2, s3, s4;
		cin >> s1 >> s2;
		int bt = 0;
		for(int i = 1; i <= s1.size(); i++){
			if(s1[i] != s2[i]){
				bt++;
				s3 += s1[i];
				s4 += s2[i];
				cout << s3 << " " << s4 << endl;
			}
		}
		for(int i = 1; i <= n; i++){
			cout << ss[i][0] << ss[i][1] << endl;
			if(s3 == ss[i][1] && s4 == ss[i][2]){
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
