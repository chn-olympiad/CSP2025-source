#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,x="";
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x+=s[i];
		}
	}
	sort(x.begin(),x.end());
	reverse(x.begin(),x.end());
	cout<<x;
	return 0;
} 
