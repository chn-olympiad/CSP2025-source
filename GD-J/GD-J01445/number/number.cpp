#include <bits/stdc++.h>
using namespace std;
map <char,int> m;
char a;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			m[s[i]]++;
		}
	}
	for (int i=9;i>=0;i--){
		a=i+'0';
		for (int j=1;j<=m[a];j++){
			cout<<a;
		}
	}
	return 0;
}
