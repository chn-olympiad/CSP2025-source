#include<bits/stdc++.h>
using namespace std;
string s,t="";

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(char ch:s){
		if(isdigit(ch)){
			t+=ch;
		}
	}
	
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	cout<<t<<'\n';
	return 0;
}
