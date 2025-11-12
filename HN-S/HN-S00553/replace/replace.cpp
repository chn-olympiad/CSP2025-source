#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define pr pair<int,int>
#define fi first
#define se second
map<int,int> mp;
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int n, q;
	cin>>n>>q;
	while(n--){
		string s1, s2;
		cin>>s1>>s2;
		mp[s1.find('b')-s2.find('b')]++;
	}
	while(q--){
		string s1, s2;
		cin>>s1>>s2;
		cout<<mp[s1.find('b')-s2.find('b')]<<'\n';
	}
	return 0;
}
