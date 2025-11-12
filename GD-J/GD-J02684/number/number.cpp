#include<bits/stdc++.h> 
using namespace std;
string s;
int a[1000010],cnt;
int main() {
	ios::sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) {
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=int(s[i]-'0');
	}
	sort(a+1,a+cnt+1);
	if(a[cnt]==0) cout<<0;
	else for(int i=cnt;i>=1;i--) cout<<a[i];
	return 0;
} 
