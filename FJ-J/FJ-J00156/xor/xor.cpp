#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>

using namespace std;

const int maxn=1e6+10;
const int inf=0x3f3f3f3f;

//bool cmp(int x,int y){
//	return x>y;
//}

int n,k,ans;
int a[maxn],sum[maxn];
int vis[maxn];

int query(int l,int r){
	return sum[r]^sum[l-1];
}

void dfs(int x,int sum){
	if(x>n){
		ans=max(ans,sum);
		return ;
	}
	
	if(sum+n-x<ans) return ;
	
	for(int i=x;i>=1;--i){
		if(vis[i]) break;
		
		if(query(i,x)==k){
			for(int j=i;j<=x;++j) vis[j]=1;
			dfs(x+1,sum+1);
			for(int j=i;j<=x;++j) vis[j]=0;
		}
	}
	
	dfs(x+1,sum);
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;++i){
			cnt+=a[i];
		}
		cout<<cnt<<'\n';
		return 0;
	}
	
	dfs(1,0);
	
	cout<<ans<<'\n'; 
	return 0;
}
