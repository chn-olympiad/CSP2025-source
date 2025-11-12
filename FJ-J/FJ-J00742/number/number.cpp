#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans="";
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans+=s[i];
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	if(ans[0]=='0')cout<<'0'<<endl;
	else cout<<ans<<endl;
	return 0;
}
