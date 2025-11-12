#include<bits/stdc++.h>
#define ll long long
#define db double
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int ll

using namespace std;
bool STA_MEMORY;

int n,m,ans,k,q;
const int N=2e5+10,mod=998244353;

int a[N][4],b[4],c[N],Mx[N];

priority_queue<int,vector<int>,greater<int> > pq;

void solve(){
	cin>>n;
	
	ans=0;
	while(!pq.empty()) pq.pop();
	rep(i,1,3) b[i]=0;
	rep(i,1,n) c[i]=mod,Mx[i]=0;
	
	rep(i,1,n){
		pii mx;
		mx={0,0};
		rep(j,1,3){
			cin>>a[i][j];
			mx=max(mx,{a[i][j],j});
		}
		b[mx.second]++;
		Mx[i]=mx.second;
		ans+=mx.first;
		rep(j,1,3){
			if(j==mx.second) continue;
			c[i]=min(c[i],mx.first-a[i][j]);
		}
	}
	
	if(max(max(b[1],b[2]),b[3])<=n/2){
		cout<<ans<<'\n';return;
	}
	
	int mxid;
	rep(i,1,3) if(b[i]>n/2) mxid=i;
	
	rep(i,1,n){
		if(Mx[i]==mxid){
			pq.push(c[i]);
			if(pq.size()>n/2){
				ans-=pq.top();
				pq.pop();
			}
		}
	}
	
	
	cout<<ans<<'\n';
}

bool END_MEMORY;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	fastIO;
	
	int c,T=1;
	cin>>T;
	while(T--){
		solve();
	}
	
	cerr<<"\n\nMemory:  "<<(&END_MEMORY-&STA_MEMORY)/1048576<<"  MB\n";
	return 0;
}

