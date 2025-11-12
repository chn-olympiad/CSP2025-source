#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
int a[maxn],y;
string s;
void solve(){
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++y]=(s[i]-'0');
	sort(a+1,a+y+1);
	for(int i=y;i>=1;i--)cout<<a[i];
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
	return 0;
}
