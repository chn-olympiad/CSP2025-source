#include<bits/stdc++.h>
using namespace std;
int a[1111111],ii=1;
bool cmp(int a,int b){
	return a>b;
}
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[ii++]=s[i]-'0';
	}
	sort(a+1,a+ii,cmp);
	for(int i=1;i<ii;i++)
		cout<<a[i];
	return 0;
}
