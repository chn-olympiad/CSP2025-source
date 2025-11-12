#include<bits/stdc++.h>
#define I using 
#define AK namespace 
#define CSP std
I AK CSP;
const int maxn=1e6+5;
int a[maxn];
int tot=0;
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++) {
		if (isdigit(s[i])) a[++tot]=(int)(s[i]-'0');
	}
	sort(a+1,a+1+tot,greater<int>());
	for (int i=1;i<=tot;i++) cout<<a[i];
	return 0;
}
