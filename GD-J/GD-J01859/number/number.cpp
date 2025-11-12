#include<bits/stdc++.h>
using namespace std;
string s,a="";
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s){
		if(c>='0' and c<='9'){
			a+=c;
		}
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	for(char c:a) cout<<c;
	
	return 0;
} 
