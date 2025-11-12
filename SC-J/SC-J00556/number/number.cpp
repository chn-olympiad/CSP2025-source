#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t;
	cin>>s;
	for(auto c:s){
		if(isdigit(c)) t+=c;
	}
	sort(t.begin(),t.end(),greater<>());
	cout<<t;
	return 0;
}