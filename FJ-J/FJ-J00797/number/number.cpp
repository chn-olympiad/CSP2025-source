#include <bits/stdc++.h>
using namespace std;
string str;
stack<char> stk;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	sort(str.begin(),str.end());
	for(auto ch:str)
		if('0'<=ch&&ch<='9') stk.push(ch);
	while(!stk.empty())
		cout<<stk.top(),stk.pop();
}
