#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],vis[N],ans;string awa;
void dfs(int now,int sum){
	if(now>n){
		ans=(ans+(sum>=m))%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(c[i]>now-sum-1&&awa[now-1]=='1') dfs(now+1,sum+1);
			else dfs(now+1,sum);
			vis[i]=0;	
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>awa;
	bool flag=1;
	for(int i=1;i<=n;i++) cin>>c[i],flag&=c[i];
	if(n!=m){cout<<1;
		dfs(1,0);
		printf("%lld\n",ans);
		return 0;
	}
	if(!flag){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++) if(awa[i-1]=='0') flag=0;
	if(!flag){
		puts("0");
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++) ans=(ans*i)%mod;
	printf("%lld\n",ans); 
	return 0; 
} 
