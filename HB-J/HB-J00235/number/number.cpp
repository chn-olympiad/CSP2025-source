#include<bits/stdc++.h>
using namespace std;
string s;
int n[15],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len;++i) if('0'<=s[i]&&s[i]<='9') ++n[s[i]-'0'];
	for(int i=9;i>-1;--i) while(n[i]--) printf("%d",i);
	return 0;
}
