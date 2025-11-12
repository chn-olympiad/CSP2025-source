#include<bits/stdc++.h>
using namespace std;
#define i128 __int128
#define ull unsigned long long
#define ll long long
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fd(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
inline void cmax(int&x,int y){x=(x>y?x:y);}
inline void cmin(int&x,int y){x=(x<y?x:y);}
int n,a[3][100005],mx[100005],mx2[100005];
inline void solve(){
	cin>>n;
	int ans=0,cnt[3]={0,0,0};
	fo(i,1,n){
		fo(j,0,2)cin>>a[j][i];
		mx[i]=0,mx2[i]=1;
		if(a[0][i]<a[1][i])swap(mx[i],mx2[i]);
		if(a[2][i]>=a[mx[i]][i])mx2[i]=mx[i],mx[i]=2;
		else if(a[2][i]>=a[mx2[i]][i])mx2[i]=2;
		ans+=a[mx[i]][i],cnt[mx[i]]++;
	}
	int tmp=max({cnt[0],cnt[1],cnt[2]});
	if(tmp<=n/2)return cout<<ans<<'\n',void();
	int p=(cnt[0]==tmp?0:(cnt[1]==tmp?1:2));
	vector<pii>v;
	fo(i,1,n)if(mx[i]==p)v.pb({a[p][i]-a[mx2[i]][i],i});
	sort(v.begin(),v.end());
	fo(i,0,tmp-n/2-1)ans-=v[i].fi;
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}
