#include<bits/stdc++.h> 
using namespace std;
string num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str,ans;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			num[str[i]-'0']+=str[i];
		}
	}
	for(int i=9;i>=0;i--){
		if(num[i].size()>0){
			ans=ans+num[i];
		}
	}
	cout<<ans;
	return 0;
} 
