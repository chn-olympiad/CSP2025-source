#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int b[15];
bool flag=true;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	for(int i = 9;i>=1;i--){
		for(int j = 1;j<=b[i];j++){
			cout<<i;
			flag=false;
		}
	}
	if(flag==true){
		cout<<0;
	}
	else{
		for(int j = 1;j<=b[0];j++){
			cout<<0;
		}	
	}
	return 0;
}
