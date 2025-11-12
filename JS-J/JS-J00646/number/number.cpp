#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> g;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(size_t i=0;i<s.size();++i) if(s[i]>='0' && s[i]<='9') g.push_back(s[i]^48);
	sort(g.begin(),g.end());
	for(int i=g.size()-1;~i;--i) printf("%d",g[i]);
	return 0;
}
