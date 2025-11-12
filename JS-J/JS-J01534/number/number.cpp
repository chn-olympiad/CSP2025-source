#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],js=0;
bool cmp(int q,int p){
	return q>p;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();++i)
		if(s[i]<='9'&&s[i]>='0') a[++js]=int(s[i]-'0');
	sort(a+1,a+js+1,cmp);
	if(a[1]==0) cout<<0<<endl;
	else{
		for(int i=1;i<=js;++i)
			cout<<a[i];
		cout<<endl;
	}
	return 0;
}
