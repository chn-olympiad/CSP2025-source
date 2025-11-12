#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string s;
vector <int> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') v.push_back(s[i]-'0');
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--) cout<<v[i];
	return 0;
}

