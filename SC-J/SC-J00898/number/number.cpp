#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000010],len,tot=0;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	len=s.size();
	for(int i=0;i<len;i++) {
		if(s[i]>='0'&&s[i]<='9') {
			num[++tot]=s[i]-'0';
		}
	}
	sort(num+1,num+tot+1,cmp);
	for(int i=1;i<=tot;i++) {
		cout<<num[i];
	}
	return 0;
}