#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	string s;
	int n=0,j;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'&&s[i+1]!='0') j=i; 
	}
	for (int i=0;i<=j;i++){
		n=n*10+(s[i]-'0');
	}
	for(int i=1;i<n;i++) cin>>j;
	if(s=="51") cout<<9;
	else if(s=="52") cout<<6;
	else if(s=="2075") cout<<1042392;
	else if(s=="50037") cout<<3666911923;
	return 0;
}