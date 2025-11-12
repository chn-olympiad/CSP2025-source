#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,tot=0,a[2000005];
string s;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') a[++tot]=(int)(s[i]-'0');
	sort(a+1,a+tot+1);
	for(int i=tot;i>0;i--) cout<<a[i];
	return 0;
}