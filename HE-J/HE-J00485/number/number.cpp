#include <bits/stdc++.h>
using namespace std;
string s1="",cnt="",s;
bool cmp(char a,char b){return a>b;}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s) if(c>='0' && c<='9') s1+=c;	
	sort(s1.begin(),s1.end(),cmp);
	for(char c:s1) cnt+=c;
	cout<<cnt;
	return 0;
}

