#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int n,a[N];
bool cmp(int a,int b){
	return a>b;
}
bool fl;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9') a[++n]=s[i]-'0';
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i){
		if(a[i]!=0) fl=true;
		if(fl) cout<<a[i];
	}
	if(!fl) cout<<a[n];
	return 0;
}
