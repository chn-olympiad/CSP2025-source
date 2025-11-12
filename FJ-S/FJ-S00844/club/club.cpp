//CSP 2025 RP++
#include <bits/stdc++.h>
#define N 100010
#define int long long
using namespace std;
int T,n,dp[N],ans,tot[N],sum[N];
struct node{
	int a,b,c,mx;
}k[N],z[N];
bool cmp1(node x,node y){
	return x.a>y.a;
}
void init(){
	memset(dp,0,sizeof(dp));
	memset(tot,0,sizeof(tot));
	memset(sum,0,sizeof(sum));
	ans=0; 
}
void dfs(int s,int cnt){
	if(s==n+1){
		ans=max(ans,cnt);
		return;
	}
	if(cnt+sum[n]-sum[s-1]<=ans) return;
	if(tot[1]<n/2){
		tot[1]++;
		dfs(s+1,cnt+k[s].a);
		tot[1]--;
	}
	if(tot[2]<n/2){
		tot[2]++;
		dfs(s+1,cnt+k[s].b);
		tot[2]--;
	}
	if(tot[3]<n/2){
		tot[3]++;
		dfs(s+1,cnt+k[s].c);
		tot[3]--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		init();
		cin>>n;
		bool flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			cin>>k[i].a>>k[i].b>>k[i].c;
			k[i].mx=max(k[i].a,max(k[i].b,k[i].c));
			if(k[i].b||k[i].c) flag1=0;
			if(k[i].c) flag2=0;
		}
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+k[i].mx;
		}
		if(flag1){
			sort(k+1,k+n+1,cmp1);
			ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=k[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		if(n<=30){
			dfs(1,0);
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
//45 
