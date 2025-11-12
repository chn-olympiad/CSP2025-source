#include<bits/stdc++.h>
using namespace std;
#define i128 __int128
#define ull unsigned long long
#define int long long
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fd(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const int mod=998244353;
inline void cmax(int&x,int y){x=(x>y?x:y);}
inline void cmin(int&x,int y){x=(x<y?x:y);}
int n,m,a[505],p[505],ans;
string s;
inline void solve(){
	cin>>n>>m>>s,s=' '+s,iota(p+1,p+1+n,1);
	fo(i,1,n)cin>>a[i];
	if(count(s.begin(),s.end(),'1')<m||n-count(a+1,a+1+n,0)<m)return cout<<0,void();
	if(n<12){
		do{
			int cnt=0;
			fo(i,1,n){
				if(cnt>=a[p[i]]||s[i]=='0')cnt++;
				if(cnt>n-m)break;
			}
			ans+=(cnt<=n-m);
		}while(next_permutation(p+1,p+1+n));
	}
	else{
		ans=1;
		fo(i,1,n)ans=ans*i%mod;
	}
	cout<<ans;
}
signed main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
