#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	string str="",ans="";
	ll num[11];
	cin>>str;
	for(int i=0;i<11;i++)num[i]=0;
	for(ll i=0;i<str.size();i++){
		if(str[i]-'0'>=0&&str[i]-'0'<10){
			num[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++){
			ans+='0'+i;
		}
	}
	cout<<ans;
	return 0;
}
