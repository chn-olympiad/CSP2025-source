#include<bits/stdc++.h>
using namespace std;
void op(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
string s;
long long js[109];
int main(){
	op();
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')js[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=js[i];j++)cout<<i;
	}
	return 0;
}
