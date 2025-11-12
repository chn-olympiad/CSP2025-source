#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return int(a)>int(b);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a+=s[i];
	sort(&a[0],&a[a.size()-1],cmp);
	cout<<a<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//+++++++[>++++++++++<-]>++.<+++[>++++++++++<-]>-.+++++++..+++.>++++[>++++++++<-]>.>+++++++++[>++++++++++<-]>---.<++++[>++++++<-]>.+++.------.--------.>++++[>++++++++<-]>+.
