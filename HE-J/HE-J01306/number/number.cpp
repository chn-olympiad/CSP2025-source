#include<bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
string s;
vector<int>val;
int main(){
	freopen("number.in","r",stdin),
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>s;
	for(auto ch:s)
		if(isdigit(ch))
			val.push_back(ch^48);
	sort(ALL(val),greater<int>());
	for(auto v:val)
		cout<<v;
	return 0;
}
//Hello! My luogu uid is 743014 pls follow me on luogu!
