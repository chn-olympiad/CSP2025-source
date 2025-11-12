#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s,d;
char c[N];
bool cmp(char x,char y) {return (x>y);}
int main() {
//	freopen("number","r",stdin);
//	freopen("number","w",stdout);
	cin>>s; d="";
	for(int i=0;i<s.size();i++) {
		if('0'<=s[i]&&s[i]<='9') d+=s[i];
	}
	for(int i=0;i<d.size();i++) {
		c[i]=d[i];
	}
	sort(c,c+d.size(),cmp);
	if(c[0]=='0') printf("0\n");
	else cout<<c<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
