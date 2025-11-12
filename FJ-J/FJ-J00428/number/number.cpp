#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],len;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	s=' '+s;
	for(int i=1;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')a[++len]=s[i]-48;
	sort(a+1,a+len+1);
	for(int i=len;i;i--)cout<<a[i];
	return 0;
}
