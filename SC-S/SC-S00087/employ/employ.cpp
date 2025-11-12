#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
int Time=clock();
bool mst;
const int N=505;
const ll mod=998244353;
string ss;
int n,m,s[N],c[N];
namespace pts8{
	bool vis[15];
	int way[15],ans;
	void dfs(int a){
		if(a==n+1){
			int cnt1=0,cnt2=0;
			for(int i=1;i<=n;i++){
				if(s[i]==0||cnt1>=c[way[i]])  cnt1++;
				else  cnt2++;
			}
			if(cnt2>=m)  ans++;
			return ;
		}
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				vis[i]=1,way[a]=i;
				dfs(a+1);
				vis[i]=0;
			}
	}
	void solve(){
		dfs(1);
		cout<<ans;
	}
}
namespace pts4{
	void solve(){
		for(int i=1;i<=n;i++)
			if(s[i]==0||c[i]==0){
				cout<<0;
				return ;
			}
		ll ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		cout<<ans;
	}
}
namespace pts12{
	void solve(){
		ll ans=1ll,tans=1ll;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		sort(c+1,c+1+n);
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(s[i]==1){
				int p=(upper_bound(c+1,c+1+n,i-1)-c)-1;
				if(p-cnt<0){
					tans=0;
					break;
				}
				tans=tans*(p-cnt)%mod,cnt++;
			}
		for(int i=n-cnt;i>=1;i--)
			tans=tans*i%mod;
		ans-=tans;
		if(ans<0)  ans+=mod;
		cout<<ans;
	}
}
bool med;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>ss;
	ss=' '+ss;
	bool flag1=1;
	for(int i=1;i<=n;i++){
		s[i]=(ss[i]=='1');
		if(s[i]!=1)  flag1=0;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n<=10)  pts8::solve();
	if(m==n)  pts4::solve();
	if(m==1)  pts12::solve();
	// cerr<<"Time:"<<1.0*(clock()-Time)/CLOCKS_PER_SEC<<"s\n";
	// cerr<<"Memory:"<<1.0*(&med-&mst)/1024.0/1024.0<<"MB\n";
	return 0;
}