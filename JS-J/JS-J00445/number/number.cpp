#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s,ans="";
	cin>>s;
	
	for(int i =0;i<(int)s.size();i++) if(isdigit(s[i])) ans+=s[i];
	
	sort(ans.begin(),ans.end(),cmp);
	
	cout<<ans;
	
	return 0;
}
