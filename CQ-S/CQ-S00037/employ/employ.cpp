#include<bits/stdc++.h>
#define int long long 
#define mod 998244353
#define ll long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=505;
int n,m,ans,a[N],b[N];
vector<int> g;
bool vis[N];
void dfs(int x){
	if(x==n){
		int x1=0,cnt=0,tot=0;
		for(auto v:g){
			if(b[v]<=x1||a[++tot]==0) {
				x1++;
			}else{
				cnt++;
			}
		}
		if(cnt>=m) {
			ans++;
//			for(auto v:g) cout<<v<<" ";
//			cout<<"\n";
		}
		ans%=mod;
		return ;
	}
	rep(i,1,n){
		if(vis[i]==1) continue;
		vis[i]=1;
		g.push_back(i);
		dfs(x+1);
		vis[i]=0;
		g.pop_back();
	}
}
signed main(){
	freopen("employ.in","r",stdin);	
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	bool f=0;
	rep(i,1,n){
		char c;
		cin>>c;
		a[i]=c-'0';
		if(a[i]!=0) f=1;
	}
	rep(i,1,n) cin>>b[i];
	bool flag=0;
	rep(i,1,n) if(a[i]==1) flag=1;
	if(flag==0) {
		cout<<0;
		return 0;
	}
	if(f==0){
		int ans=1;
		rep(i,1,n) {
			ans*=2;
			ans%=mod;
		}
		rep(i,1,m-1){
			int t1=1,t2=1;
			rep(j,1,i) t1*=j,t2*=(n+1-i);
			ans-=t2/t1;
			if(ans<0) ans+=mod;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) {
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(0);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
