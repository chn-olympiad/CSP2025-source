#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	vector<char> v;
	cin>>n;
	for(int i=0;i<n.size();i++){
		int a=int(n[i]);
		if(a>=48 and a<=57)
			v.push_back(n[i]);
	}
	sort(v.begin(),v.end(),greater<char>());
	for(auto x:v) cout<<x;
	return 0;
}
