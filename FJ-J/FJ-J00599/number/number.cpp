#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
vector<int> w;

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();++i){
		if(s[i]>='0'&&s[i]<='9') w.push_back(s[i]-'0');
	}
	sort(w.begin(),w.end());
	int n=w.size()-1;
	for(int i=n;i>=0;--i) cout<<w[i];
	return 0;
}
