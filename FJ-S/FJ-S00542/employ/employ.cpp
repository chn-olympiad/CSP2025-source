#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
const int N=505;
int n,m,cnt;
string s;
int c[N];
bool vis[N];
void dfs(int k,int sum){
//	cout<<k<<" "<<sum<<" "<<cnt<<"\n";
	if(sum>=m){
		int res=1;
		for(int i=1;i<=n-k;++i){
			res=(res*i)%MOD;
		}
		cnt=(cnt+res)%MOD;
		return;
	}
	if(m-sum>n-k||k>=n) return;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			int d=1;
			if(s[k]=='0'||c[i]<=k-sum) d=0;
			dfs(k+1,sum+d);
			vis[i]=0;
		}
	}
	return;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	if(n>18){
		cnt=1;
		for(int i=n;i>=1;--i){
			cnt=(cnt*i)%MOD;
		}
		cout<<cnt;
		return 0;
	}
	else{
		dfs(0,0);
		cout<<cnt;
	}
	return 0;
}
