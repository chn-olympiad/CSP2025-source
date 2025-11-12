#include<bits/stdc++.h>
using namespace std;
const int maxn=1003;
const long long mod=998244353;
int n,m,s[maxn],c[maxn],sum[maxn];
long long ans=0,deans[maxn];
bool vis[maxn];
void dfs(int t,int res){
	if(res>=m){
		ans+=deans[n-t];
		ans%=mod;
		return;
	}
	if(res+sum[t+1]<m)return;
	if(t==n)return;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		int sum=res;
		if(t-res<c[i]&&s[t+1]==1)sum++;
		dfs(t+1,sum);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	deans[0]=1;
	for(int i=1;i<=n;i++){
		deans[i]=deans[i-1]*i;
		deans[i]%=mod;
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		char t;cin>>t;
		s[i]=t-'0';
		if(s[i]==0)flag=0;
	}
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]+s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(flag){
		ans=1;
		for(long long i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		return 0;
	}
	else dfs(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
