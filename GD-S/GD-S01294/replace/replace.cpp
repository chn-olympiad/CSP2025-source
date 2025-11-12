#include <bits/stdc++.h>
using namespace std;
int n,q;
const int N = 2e5 + 5;
struct node{
	string s1,s2;
}a[N];
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i].s1 >> a[i].s2;
		mp[a[i].s1] = a[i].s2;
	}
	while(q--){
		int ans = 0;
		string s,ss;
		cin >> s >> ss;
		if(s.size() != ss.size()){
			cout << 0 << endl;
			continue;
		}
		int st,ed;
		for(int i = 0;i < s.size();i++){
			if(s[i] != ss[i]){
				st = i;
				break;
			}
		}
		for(int i = s.size() - 1;i >= 0;i--){
			if(s[i] != ss[i]){
				ed = i;
				break;
			}
		}
		//cout << st << ' ' << ed << endl;
		ans = 0;
		for(int i = 0;i < s.size();i++){
			for(int j = 1;j <= s.size() - i;j++){
				//cout << i << ' ' << j << endl;
//				cout << s.substr(i,j) << ' ' << ss.substr(i,j) << endl;
//				cout << mp[s.substr(i,j)] << endl;
				if(mp[s.substr(i,j)] == ss.substr(i,j) && i <= st && i + j > ed){
					ans++;
					//cout << i << ' ' << j << endl;
					
				}
			}
		}
		cout << ans << endl;
	}
} 
