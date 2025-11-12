#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m;
char c[505];
int lim[505];
int cnt[505];
int l[505],r[505];
int ans;
void dfs(int step,int un){
	if(un>n-m)return;
	if(step==n+1){
		ans++;
		return;
	}
	if(c[step]=='0'){
		dfs(step+1,un+1);
		return;
	}
	for(int i=r[0];i!=n+1;i=r[i]){
		int ls=l[i],rs=r[i];
		l[rs]=ls,r[ls]=rs;
		if(lim[i]<=un)dfs(step+1,un+1);
		else dfs(step+1,un);
		l[rs]=i,r[ls]=i;
	}
}
int solve(){
	if(m==n){
		int now=1;
		for(int i=1;i<=n;i++){
			if(c[i]=='0')return 0;
			if(lim[i]==0)return 0;
			now=1ll*now*i%mod;
		}
		return now;
	}
	if(m==1){
		int now=1;
		for(int i=1;i<=n;i++)cnt[lim[i]]++;
		for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
		for(int i=1;i<=n;i++)now=1ll*now*i%mod;
		int res=1;
		int cur1=0,cur2=0;
		for(int i=1;i<=n;i++){
			if(c[i]=='1'){
				res=1ll*res*(cnt[i-1]-cur2)%mod;
				cur2++;
			}
			else{
				cur1++;
				res=1ll*res*cur1%mod;
			}
		}
		return (now-res+mod)%mod;
	}
	ans=0;
	for(int i=1;i<=n;i++)l[i]=i-1,r[i]=i+1;
	r[0]=1,l[n+1]=n;
	dfs(1,0);
	int nt=0;
	for(int i=1;i<=n;i++){
		if(c[i]=='0'){
			nt++;
			ans=1ll*ans*nt%mod;
		}
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)cin>>lim[i];
	cout<<solve()<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
