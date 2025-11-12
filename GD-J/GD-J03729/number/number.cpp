#include <bits/stdc++.h>
using namespace std;
int b[1000005];
long long cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9') b[++cnt]=s[i]-'0';
	}
	sort(b+1,b+cnt+1);
	for(int i=cnt;i>=1;i--) printf("%d",b[i]);
	return 0;
}
