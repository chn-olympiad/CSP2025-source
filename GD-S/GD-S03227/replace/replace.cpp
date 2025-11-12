#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define int LL
#define For(i,t,n) for(int i=t;i<=n;++i)
#define foR(i,t,n) for(int i=t;i>=n;--i)

const int MAXN=2e5+5;
int n,q,ans;
string s1[MAXN],s2[MAXN];
string t1,t2,tt;

void solve(){
	cin>>n>>q;
	For(i,1,n) cin>>s1[i]>>s2[i];
	while(q--){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n"; continue;
		}
		For(i,1,n){
			tt=t1;
			int pos=tt.find(s1[i]);
			if(pos==-1) continue;
			tt.replace(pos,s1[i].size(),s2[i]);
			if(tt==t2) ++ans;
		} 
		cout<<ans<<'\n';
	}
}
#define thlog5
signed main(){
	//rp=EOF
	ios::sync_with_stdio(0);
#ifdef thlog5
	#define TimuMingzi "replace"
	freopen(TimuMingzi".in","r",stdin);
	freopen(TimuMingzi".out","w",stdout);
#endif
	solve();
	return 0;
}

