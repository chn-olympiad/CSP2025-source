#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000000+5],cnt;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	if(s[i]<='9' && s[i]>='0') a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<a[i];
	return 0;
}