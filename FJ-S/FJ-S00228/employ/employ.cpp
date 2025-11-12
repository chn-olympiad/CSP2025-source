#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+5;
const int mod=998244353;
int n,m;
string s;
int a[N],p[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0' || cnt>=a[p[i]]) cnt++;
		ans+=(n-cnt>=m);
		if(ans==mod) ans=0;
	}
	while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
}
