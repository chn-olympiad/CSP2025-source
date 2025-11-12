#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000005];
int top=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			c[++top]=s[i];
		}
	}
	sort(c+1,c+top+1);
	for(int i=top;i>=1;i--){
		cout<<c[i];
	}
	return 0;
}
