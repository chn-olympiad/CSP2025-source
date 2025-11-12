#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int c[1000005];
int n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]<='9' && s[i]>='0'){
			c[++n]=s[i]-'0';
		}
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;++i){
		cout<<c[i];
	}
	return 0;
}

