#include<bits/stdc++.h>
#define ll long long
const int N=520,mod=998244353;
using namespace std;
int n,m,ans,c[N];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	cin>>n>>m;
	cin>>s;
	int f=1;
	for(int i=0;i<n;++i) if(s[i]!='1') f=0;
	for(int i=1;i<=n;++i) cin>>c[i];
	sort(c+1,c+n+1);
	if(f){
		int cnt=1;
		while(c[cnt]==0) cnt++;
		if(n-cnt<m) ans=0;
		cout<<ans;
	}
	freopen("employ.out","w",stdout);
	return 0;
}
