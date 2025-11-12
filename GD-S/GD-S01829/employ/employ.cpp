#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=505,mod=998244353;

int n,a[maxn];
string st;
bool Check(){
	for(int i=0;i<n;i++)
		if(st[i]=='0') return true;
	for(int i=1;i<=n;i++)
		if(!a[i]) return true;
	return false;
}

int m,sum[maxn];
ll ans;
bool vis[maxn];
void Dfs(int x,int k){
	if(sum[x]+k<m) return;
	if(x==n+1){
		ans++,ans%=mod;
		return;
	}
	int nwk=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(x-1-k>=a[i]||st[x-1]=='0') Dfs(x+1,k);
			else Dfs(x+1,k+1);
			vis[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>st;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(m==n){
		if(Check()){
			printf("0");
			return 0;
		}
		ll ans=1;
		for(int i=1;i<=n;i++)
			(ans*=i)%=mod;
		printf("%lld",ans);
		return 0;
	}
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1];
		if(st[i-1]=='1') sum[i]++;
	}
	Dfs(1,0);
	printf("%lld",ans);
	return 0;
}
