#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	string s;cin>>s;
	sort(begin(s),end(s),greater<>());
	for(char c:s)if(c<='9'&&c>='0')cout<<c;
	return 0;
}