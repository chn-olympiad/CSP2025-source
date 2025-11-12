#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++) c[i]=s[i];
	sort(c,c+s.length());
	for(int i=s.length()-1;i>=0;i--) if(c[i]>='0'&&c[i]<='9') cout<<c[i];
	return 0;
}
