#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n,m,c[20],ans,vis[20];
string str;

void dfs(int x,int cnt,int p){
	if(x==n){
		if(cnt>=m)ans++;
		ans%=998244353;
		return;
	}
	for(int i=0;i<n;++i){
		if(!vis[i]){
			vis[i]=1;
			if(str[i]=='0'){
				dfs(x+1,cnt,p+1);
			}else if(p>=c[x+1]){
				dfs(x+1,cnt,p+1);
			}else{
				dfs(x+1,cnt+1,p);
			}
			vis[i]=0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}

