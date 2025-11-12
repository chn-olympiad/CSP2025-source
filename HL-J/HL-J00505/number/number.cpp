#include<bits/stdc++.h>
using namespace std;
string s;
char ss[1000010];
long long n=0;
bool cmp(int x,int y) {
	return y<x;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sl=s.size();
	for(int i=0; i<sl; i++) {
		if(s[i]=='0')  ss[n++]='0';
		if(s[i]=='1')  ss[n++]='1';
		if(s[i]=='2')  ss[n++]='2';
		if(s[i]=='3')  ss[n++]='3';
		if(s[i]=='4')  ss[n++]='4';
		if(s[i]=='5')  ss[n++]='5';
		if(s[i]=='6')  ss[n++]='6';
		if(s[i]=='7')  ss[n++]='7';
		if(s[i]=='8')  ss[n++]='8';
		if(s[i]=='9')  ss[n++]='9';

	}
	sort(ss,ss+n,cmp);
	for(int i=0; i<n; i++)
		cout<<ss[i];
	return 0;
}
