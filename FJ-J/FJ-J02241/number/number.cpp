#include<bits/stdc++.h>
using namespace std;
	
string s;
vector<char> ans;

bool cmp(char x,char y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9')
			ans.push_back(s[i]);
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i];
	return 0;
} 
