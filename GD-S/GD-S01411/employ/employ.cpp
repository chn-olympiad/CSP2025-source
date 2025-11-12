#include<bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int kmaxN = 510;
int n,m,c[kmaxN],di[kmaxN],maxc,dfc[kmaxN]; 
bool fa = 1;
bool vis[kmaxN];
long long ans;
void dfs(int nc,int num,int pas){
	if(num == n){
		if(pas >= m) ans++;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = 1;
			if(di[num] == 0) dfs(nc,num+1,pas+1);
			else{
				if(c[i] > nc) dfs(nc+1,num+1,pas);
			} 
			vis[i] = 0;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char cc;
	for(int i = 1;i <= n;i++){
		cin>>cc;
		di[i] = cc-'0';
		if(!di[i]){
			fa = 0;
		}
	}
	for(int i = 1,d;i <= n;i++){
		cin>>d;
		dfc[i] = d;
		c[d]++;
		maxc = max(d,maxc);
	}
	
	if(fa){
		ans = 1;
		for(int i = 2;i <= n;i++){
			ans = (ans*i) %MOD;
		}
		cout<<ans;
	}
	else{
		if(m == 1){
//			ans = c[i];
			
		}else{
			ans = n*m % MOD;
			cout<<ans;	
		}

	}
	return 0;
} 
