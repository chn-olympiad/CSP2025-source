#include<bits/stdc++.h>
using namespace std;
string s;
int b[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			b[s[i]]++;
		}
	}
	bool flag=0;
	for(int i='9';i>='0';i--){
		if(b[i]){
			if(i=='0'&&!flag)cout<<0;
			else{
				flag=1;
				for(int j=1;j<=b[i];j++)cout<<char(i);
			}
		}
	}
	return 0;
}
