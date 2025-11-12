#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
inline string reads(){
	string x="";
	char c=getchar();
	while(c==' '||c=='\n') c=getchar();
	while(c!=' '&&c!='\n'){
		x+=c;
		c=getchar();
	}
	x+='\0';
	return x;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s=reads();
	for(int i=0;s[i];++i)++m[s[i]];
	for(char i='9';i>='0';--i)
		while(m[i]){
			putchar(i);
			--m[i];
		}
	putchar('\n');
	return 0;
}
