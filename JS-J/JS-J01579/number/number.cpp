#include <bits/stdc++.h>
using namespace std;
string s;
string ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i < s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			ans+=s[i];
		}
	}
	sort(ans.begin(),ans.end());
	if(ans[ans.size()-1]==0){
		cout<<0;
	}else{
		for(int i=ans.size()-1;i>=0;i--){
			cout<<ans[i];
		}
	}
	return 0;
}
