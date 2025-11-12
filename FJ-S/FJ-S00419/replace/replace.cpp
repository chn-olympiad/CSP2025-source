#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
string s1[N] , s2[N];
int ans;
void bfs(string a , string b){
	map<string , int> mp;
	queue<string> q;
	q.push(a);
	mp[a] = 1;
	while(q.size()){
		auto t = q.front();
		int n = t.size();
		q.pop();
		for(int i = 0 ; i < t.size() ; i ++){
			for(int j = i + 1 ; j < t.size(); j ++){
				string tmp = t.substr(i + 1 , j);
				string t2 = t.substr(0 , i);
				string t3 = t.substr(j + 1 , n - 1);
				for(int i = 1 ; i <= n ; i ++){
					if(tmp == s1[i]) tmp = s2[i];
				}
				string ns = t2 + tmp + t3;
				if(mp[ns] != 1){
					if(ns == b) ans ++;
					mp[ns] = 1;
					q.push(ns);
				}
			} 
		}
	}
}
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , q;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++) cin >> s1[i] >> s2[i];
	while(q --){
		ans = 0;
		string a , b;
		cin >> a >> b;
		bfs(a , b);
		cout << ans << '\n';
	}
	return 0;
}
