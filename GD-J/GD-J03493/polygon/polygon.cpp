#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=5005;
int n;
int a[N];
ll ans;
bool b[N];
void dfs(int s,int t,int sum,int Maxn){
	if(s==t+1){
		if(sum<=Maxn*2){
			return;
		}
		ans=(ans+1)%mod;
		return;
	}
	dfs(s+1,t,sum+a[s],max(Maxn,a[s]));
	dfs(s+1,t,sum,Maxn);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=20){
		dfs(1,n,0,0);
		cout<<ans;
	}
	else{
		ll g;
		for(int i=3;i<=n;i++){
			g=1;
			memset(b,0,sizeof(b));
			for(int j=n;j>=n-i+1;j++){
				ll u=j;
				for(int k=1;k<=i;k++){
					if(b[k])continue;
					if(u%k!=0)continue;
					u/=k;
				}
				g=(g*u)%mod;
				
			}
			ans=(ans+g)%mod;
		}
		cout<<ans;
	}
	return 0;
} 
