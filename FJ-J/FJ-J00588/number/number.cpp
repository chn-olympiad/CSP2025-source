#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
map<char,ll>T;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		T[s[i]]++;
	}
	for(char i='9';i>='0';i--){
		for(int j=1;j<=T[i];j++)cout<<i;
	}
	return 0;
}
