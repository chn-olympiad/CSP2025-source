#include<bits/stdc++.h>
#define int long long 
using namespace std;
int t,a[11451400];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();++i) if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0';
	sort(a+1,a+1+t);
	for(int i=t;i>=1;i--) cout<<a[i];
}
