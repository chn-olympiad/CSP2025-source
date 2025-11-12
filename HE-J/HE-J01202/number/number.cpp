#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[100];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		if(a[i]) while(a[i]--) cout<<i;
	return 0;
}
