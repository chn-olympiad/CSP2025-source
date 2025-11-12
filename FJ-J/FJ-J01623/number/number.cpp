#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
string s;
int n,ans[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') ans[++n]=s[i]-'0';
	sort(ans+1,ans+1+n);
	for(int i=n;i>=1;i--) cout<<ans[i];
	return 0;
}
