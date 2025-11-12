#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000005]; 
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]<='9'&&s[i]>='0') a[++n]=s[i]-'0';
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--) cout<<a[i];
	return 0;
}
