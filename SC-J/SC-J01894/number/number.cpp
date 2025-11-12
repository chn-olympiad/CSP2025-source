#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define uint unsigned int
#define str string
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	str s;
	vector<int> v;
	cin>>s;
	for(uint i=0;i<s.size();i++){
		if((s[i]>='0')&&(s[i]<='9')){
			v.emplace_back(s[i]-'0');
		}
	}
	sort(v.rbegin(),v.rend());
	for(uint i=0;i<v.size();i++){
		cout<<v[i];
	}
	return 0;
}