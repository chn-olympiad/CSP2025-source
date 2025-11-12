#include<bits/stdc++.h>
using namespace std;
string s;
int n,cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s; n=s.size();
	for(int i=0;i<n;++i){
		if(s[i]<'0' || s[i]>'9') continue;
		++cnt[s[i]-'0'];
	}
	for(int i=9;i>=0;--i){
		for(int j=1;j<=cnt[i];++j)
			putchar(i+'0');
	}
	puts("");
	return 0;
}
