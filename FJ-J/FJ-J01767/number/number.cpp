#include <bits/stdc++.h>
using namespace std;
string s;
char ch[1000001];
int cnt=1;
bool cmp(char a,char b) {
	return a>b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0') {
			ch[cnt]=s[i];
			cnt++;
		}
	}
	sort(ch+1,ch+s.size()+1,cmp);
	for(int i=1; i<=cnt-1; i++) cout<<ch[i];
	return 0;
}

