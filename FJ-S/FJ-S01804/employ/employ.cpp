#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10;

int n,m,ans;
string s;
int cnt_;
int a[N];
bool vis[N];
int p[N];

void dfs(int l){
	if(l>n){
		int sum=0,fai=0;
		for(int i=1;i<=n;i++){
			if(fai>=p[i]) fai++;
			else if(s[i-1]=='0') fai++;
			else sum++;
		}
		if(sum>=m){
			ans++;
			return;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		p[l]=a[i];
		vis[i]=1;
		dfs(l+1);
		vis[i]=0;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	ios::sync_with_stdio(0),std::cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i]) cnt_++;
	}
	if(n-cnt_<m){
		cout<<0;
		return 0;
	}
	if(n<=30){
		dfs(1);
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
