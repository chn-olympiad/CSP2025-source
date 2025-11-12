#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
const ull MOD = 998244353;
const ull N = 505;

bool f=1;
int n,m,res,vis[N],c[N],dp[N],ans[N];
char ch;

void dfs(const int& x,const int& y){
	if(x==n){
//		std::cout<<n<<" "<<y<<"\n";
		if(n-y>=m)res++;
//		std::cout<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" ";
//		std::cout<<"|"<<y<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
//		std::cout<<dp[i]<<" "<<i<<"\n";
		if(!dp[i]){
			dp[i]=1;
//			std::cout<<i<<" "<<y<<"\n";
//			std::cout<<c[i]<<"\n";
			ans[x+1]=i;
			if(y>=c[i]||vis[x+1]==0)dfs(x+1,y+1);
			else dfs(x+1,y);
//			ans[x+1]=0;
			dp[i]=0;
		}
	}
//	std::cout<<"\n";
}

signed main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>ch;
		vis[i]=ch-'0';
//		std::cout<<vis[i];
		if(ch=='0'){
			f=0;
		}
		if(ch=='0'&&m==n){
			return std::cout<<0,0;
		}
	}
	for(int i=1;i<=n;i++){
		std::cin>>c[i];
		if(c[i]==0&&m==n)
			return std::cout<<0,0;
	}
	if(f){
		res=1;
		for(int i=n;i>1;i--){
			res=(res*i)%MOD;
		}
		std::cout<<res;
		return 0;
	}
	
	dfs(0,0);
	
	std::cout<<res;
	return 0;
}