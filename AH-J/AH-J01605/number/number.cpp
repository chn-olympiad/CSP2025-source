#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (auto p:s)
		if (p>='0' && p<='9')
			v.push_back(p-'0');
	sort(v.begin(),v.end(),greater<int>());
	for (auto p:v) cout<<p;
	return 0;
}
