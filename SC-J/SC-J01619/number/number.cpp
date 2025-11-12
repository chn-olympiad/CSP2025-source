#include<bits/stdc++.h>
using namespace std;
string S,ans;
signed main(){
#ifndef DEBUG
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#endif
//	freopen("number\\number4.in","r",stdin);
//	freopen("number\\number.out","w",stdout);
	cin>>S;
	for (const char &c:S) if (isdigit(c)) ans+=c;
	sort(ans.begin(),ans.end(),[&](char a,char b){return a>b;});
	cout<<ans<<"\n";
}