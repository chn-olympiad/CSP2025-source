// need long long ? neednt
// time ? O(n)
// space ? n
// max num ? N=1e6
// freopen ? yes
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	vector<int> v;
	for(int i=0;i<(int)s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.rbegin(),v.rend());
	for(int i=0;i<(int)v.size();i++) cout<<v[i];
	cout<<endl;
	return 0;
}
