#include<bits/stdc++.h>
using namespace std;
long long n[11];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[s[i]-'0']++;
		}
	}
	string h="";
	for(int i=9;i>=0;i--){
		for(int j=1;j<=n[i];j++)h=h+(char)(i+'0');
	}
	if(h[0]=='0'&&h[h.size()-1]=='0')cout<<0;
	else cout<<h;
	return 0;
} 
