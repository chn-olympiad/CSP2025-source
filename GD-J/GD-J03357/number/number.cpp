#include<bits/stdc++.h>
using namespace std;
string s,t;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s)if(isdigit(i))t+=i;
	sort(t.begin(),t.end(),greater<char>());
	return cout<<t,0;
}
