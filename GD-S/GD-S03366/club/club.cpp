#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)

using namespace std;

constexpr int N=1e5+10;

int n;
int a[N][4];
int ch[N],cnt[4];

void solve(){
	cin>>n;
	int ans=0;
	memset(cnt,0,sizeof(cnt));
	rep(i,1,n){
		rep(j,1,3) cin>>a[i][j];
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) ch[i]=1,cnt[1]++,ans+=a[i][1];
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) ch[i]=2,cnt[2]++,ans+=a[i][2];
		else ch[i]=3,cnt[3]++,ans+=a[i][3];
	}
	if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
		cout<<ans<<"\n";
		return;
	}
	int t=0;
	if(cnt[1]>n/2) t=1;
	else if(cnt[2]>n/2) t=2;
	else t=3;
	vector<int> vec;
	rep(i,1,n){
		if(ch[i]==t){
			int maxa=0;
			rep(j,1,3) if(j!=t) maxa=max(maxa,a[i][j]);
			vec.emplace_back(a[i][t]-maxa);
		}
	}
	sort(vec.begin(),vec.end());
	rep(i,1,cnt[t]-n/2) ans-=vec[i-1];
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	
	return 0;
}
