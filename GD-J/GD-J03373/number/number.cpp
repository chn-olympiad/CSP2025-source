#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define debug(nm,val) cout<<"Debug :"<<nm<<' '<<val<<'\n'
using namespace std;

signed main () {

	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	
	string s; cin>>s;
	
	vector <int> ans;
	int len=s.length ();
	for (int i=0;i<len;i++)
		if (s[i]>='0' && s[i]<='9') ans.push_back (s[i]-'0'); 
	
	sort (ans.rbegin (),ans.rend ());
	
	for (auto i : ans)
		printf ("%lld",i);
	
	printf ("\n");
	
	return 0;
}

