#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(a,b,c) for(int a=(b);a<=(c);a++)
#define per(a,b,c) for(int a=(c);a>=(b);a--)
#define fc freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
#define debug(x) cout<<x<<'\n';
const int N=510;
int c[N],a[N];
void solve()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s=' '+s;
	int cnt=0;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) a[i]=i;
	do{
		int bt=0;//被淘汰的人数
		int tmp=0;
		for(int i=1;i<=n;i++)
		{
			if(c[a[i]]<=bt||s[i]=='0') 
			{
				++bt;	
			}	
			else ++tmp;
		} 
		if(tmp>=m) {
			++cnt;
		}
	}
	while(next_permutation(a+1,a+n+1));
	cout<<cnt<<'\n';
}
signed main()
{
	fc;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
