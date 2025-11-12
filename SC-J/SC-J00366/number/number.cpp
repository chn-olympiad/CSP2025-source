#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s,se="";cin>>s;
	for(char c:s){
		if(isdigit(c))se+=c;
	}
	sort(se.begin(),se.end(),greater<char>());
	cout<<se;
	return 0;
}