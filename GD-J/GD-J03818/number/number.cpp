#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main(){
#ifndef XYZ
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s,t;
	cin>>s;
	for(auto i:s){
		if(isdigit(i))t.push_back(i);
	}
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	cout<<t;
	return 0;
}

