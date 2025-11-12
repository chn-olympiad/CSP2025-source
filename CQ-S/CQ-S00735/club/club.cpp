#include<bits/stdc++.h>
#define int long long
#define double long double
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define per(i,r,l) for(int i=(r),i##end=(l);i>=i##end;--i)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int maxn=1e6+10,maxm=1e6+10,mod=998244353,inf=INT_MAX;
inline int ksm(int x,int k,int mod=mod){
	int ans=1;
	for(x=x%mod;k;k>>=1,x=x*x%mod) if(k&1) ans=ans*x%mod;
	return ans;
}

int T,n,ans,a[maxn][3],b[maxn],cl[maxn],cnt[10];

signed submain(){
	cin>>n,cnt[0]=cnt[1]=cnt[2]=ans=0;
	rep(i,1,n){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		int mx=max(a[i][0],max(a[i][1],a[i][2]));
		ans+=mx;
		if(a[i][0]==mx) ++cnt[0],cl[i]=0;
		else if(a[i][1]==mx) ++cnt[1],cl[i]=1;
		else ++cnt[2],cl[i]=2;
	}
	int id=0;
	if(cnt[1]>cnt[id]) id=1;
	if(cnt[2]>cnt[id]) id=2;
	if(cnt[id]>n/2){
		rep(i,1,n) if(cl[i]==id) swap(a[i][0],a[i][id]),b[i]=a[i][0]-max(a[i][1],a[i][2]);
		else b[i]=inf;
		sort(b+1,b+n+1);
		rep(i,1,cnt[id]-n/2) ans-=b[i];
	}
	cout<<ans<<'\n';
	return 0;
}

signed main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	rep(o,1,T) submain();
	return 0;
}
