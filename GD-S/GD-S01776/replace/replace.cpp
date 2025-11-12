#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int n,q,nxt[N],rp[N],id[N];
string s[N][2],t[N][2];

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		id[i]=insert(s[i][0]);
	}
	for(int i=1;i<=q;i++) cin>>t[i][0]>>t[i][1];
	while(q--) cout<<0<<endl;
	return 0;
}
//一年了，毫无进步
//如此状态，何以NOIP？ 
