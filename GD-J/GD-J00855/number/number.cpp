#include<bits/stdc++.h>
using namespace std;
string s;
char s2[1000001];
int t;
bool f;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			s2[t]=s[i],t++;
	sort(s2,s2+t,cmp);
	if(s2[0]=='0')cout<<0;
	else cout<<s2;
	return 0;
}
