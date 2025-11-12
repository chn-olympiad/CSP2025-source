#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)

using namespace std;

constexpr int N=510,P=998244353;

int n,m,c[N];
string s;
bitset<N> vis;
int ans=0;
//vector<int> vec;

void dfs(int u,int a,int b){
	if(u==n+1){
		if(a>=m){
//			for(auto v:vec)cout<<v<<" ";
//			puts("");
//			int tmp=0;
//			int len=0;
//			rep(i,1,n){
//				if(s[i]=='0') len++;
//				else{
//					if(c[vec[i-1]]>len) tmp++,len=0;
//					else len++;
//				}
//			}
//			printf("tmp:%lld\n",tmp);
			ans++;
		}
		return;
	}
	rep(i,1,n){
		if(vis[i]) continue;
		vis[i]=1;
//		vec.emplace_back(i);
		if(s[u]=='0') dfs(u+1,a,b+1);
		else{
			if(c[i]>b) dfs(u+1,a+1,0);
			else dfs(u+1,a,b+1);
		}
		vis[i]=0;
//		vec.pop_back();
	}
}


signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	rep(i,1,n) cin>>c[i];
	
	if(n==m){
		rep(i,1,n){
			if(s[i]=='0'||c[i]==0){
				cout<<0;
				return 0;
			}
		}
		int ans=1;
		rep(i,1,n) ans=ans*i%P;
		cout<<ans;
		return 0;
	}else if(m==1){
		sort(c+1,c+n+1);
		int tot=1,ans=1;
		rep(i,1,n) tot=tot*i%P;
		int cnt1=0;
		for(int i=1,j=1;i<=n;i++){
			if(s[i]=='0') continue;
			while(j<=n&&c[j]<i) j++;
			ans=ans*(j-1-cnt1)%P;
			cnt1++;
		}
		rep(i,1,n-cnt1) ans=ans*i%P;
		cout<<(tot-ans+P)%P;
		return 0;
	}
	
	dfs(1,0,0);
	cout<<ans;
	
	return 0;
}

















