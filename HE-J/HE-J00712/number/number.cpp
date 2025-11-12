#include<bits/stdc++.h>
using namespace std;
string s;
long long ton[15]={0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			ton[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<ton[i];j++){
			cout<<i;
		}
	}
	return 0;
}
