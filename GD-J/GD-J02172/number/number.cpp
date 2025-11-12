#include<bits/stdc++.h>
using namespace std;
string s;
vector<char> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s)
		if(isdigit(c)) a.push_back(c);
	sort(a.begin(),a.end(),[](char x,char y){return x>y;});
	for(char i:a) cout<<i;
	return 0;
}
