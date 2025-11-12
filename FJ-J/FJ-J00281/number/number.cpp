#include<bits/stdc++.h>
using namespace std;
const int MAXX=1e6+10;
string s;
char c[MAXX];
int t;
bool cmp(char x,char y){
	if(x>y) return 1;
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t++;
			c[t]=(char)s[i];
		}
	}
	sort(c+1,c+t+1,cmp);
	for(int i=1;i<=t;i++)
		printf("%c",c[i]);
	return 0;
}