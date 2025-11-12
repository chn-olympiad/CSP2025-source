#include<bits/stdc++.h>
using namespace std;
string s;int n;
char ch[1000005];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i)
		if(s[i]>='0'&&s[i]<='9')
			ch[++n]=s[i];
	sort(ch+1,ch+n+1,cmp);
	for(int i=1;i<=n;++i)cout<<ch[i];
	return 0;
}
