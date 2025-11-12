#include<bits/stdc++.h>
using namespace std;
string s;
string ans[10];
bool f[10];
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[s[i]-'0']+=s[i];
			f[s[i]-'0']=1;
		}
	}
	for(int i=9;i>=0;i--){
		if(f[i]){
			cout<<ans[i];
		}
	}
	return 0;
}
