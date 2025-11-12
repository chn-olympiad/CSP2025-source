#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],g;
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			g++;
			a[g]=s[i]-'0';
		}
	}
	sort(a+1,a+g+1);
	for(int i=g;i>=1;i--){
		c=a[i];
		cout<<c+'0';
	}
	return 0;
}
