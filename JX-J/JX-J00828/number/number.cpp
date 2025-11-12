#include <iostream>
#include <string>
using namespace std;
string s,ans;
char t;
int data[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			data[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		t='0'+i;
		for(int j=0;j<data[i];j++){
			ans=ans+t;
		}
	}
    cout<<ans;
    return 0;
}
