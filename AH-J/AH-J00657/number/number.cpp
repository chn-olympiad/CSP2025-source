#include<bits/stdc++.h>
using namespace std;
string s;int a[1000005],l,l1;
bool cmp(const int &a,const int &b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;l1=s.size();
	for(int rp=0;rp<l1;rp++)
		if(s[rp]>='0'&&s[rp]<='9') a[++l]=s[rp]-'0';
	sort(a+1,a+l+1,cmp);
	for(int rp=1;rp<=l;rp++) cout<<a[rp];
	return 0;
}
