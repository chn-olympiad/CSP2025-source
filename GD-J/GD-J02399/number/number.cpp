#include<bits/stdc++.h>
using namespace std;
string s,num;
int main(){
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(char c:s)if(isdigit(c))num+=c;
	sort(num.begin(),num.end(),[](char x,char y){return x>y;});
	if(num.front()=='0')cout<<"0";
	else cout<<num;
	return 0;
}
