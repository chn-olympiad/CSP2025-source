#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
const int N=5005;
int n,cnt;
int a[N];
bool vis[N];
int pw(int x){
	int res=1,a=2;
	while(x){
		if(x&1) res=(res*a)%MOD;
		a=(a*a)%MOD;
		x>>=1;
	}
	return res;
}
void dfs(int k,int last,int sum,int mx){
	if(k>=3&&sum>2*mx){
		cnt=(cnt+pw(n-last))%MOD;
		return;
	}
	for(int i=last+1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			dfs(k+1,i,sum+a[i],max(mx,a[i]));
			vis[i]=0;
		}
	}
	return;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f){
		cout<<pw(n)-1-n-(n*(n-1))/2;
		return 0;
	}
	sort(a+1,a+1+n,greater<int>());
	dfs(0,0,0,0);
	cout<<cnt;
	return 0;
}
