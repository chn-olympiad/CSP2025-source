#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt;
char ans[1000005];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s) if(isdigit(c)) ans[++cnt]=c;
	sort(ans+1,ans+1+cnt,greater<int>());
	for(int i=1;i<=cnt;++i) cout<<ans[i];
}
