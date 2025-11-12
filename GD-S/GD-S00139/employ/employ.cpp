#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5e2+5,mod=998244353;
long long n,m,a[MAXN],c[MAXN],pb[MAXN],inv[MAXN],tmp[MAXN],vis[MAXN],ans=0,val[MAXN];
long long qpow(long long a,long long b){
	long long ans=1;a%=mod;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void dfs(int x){
	if(x>n){
		int last=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(last>=c[tmp[i]]) last++;
			else if(pb[i]==0) last++;
			else cnt++;
		}
		if(cnt>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		tmp[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long cnt=0,num=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		char ch;cin>>ch;
		pb[i]=ch-'0';
		cnt+=(ch-'0');
	}
	for(long long i=1;i<=n;i++) cin>>c[i],num+=(c[i]!=0);
	
	if(n<=10){
		dfs(1);
		cout<<ans;
	}
	else if(cnt==n){
		long long ans=1;
		for(long long i=n-num;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
	}
	else if(m==1){
		long long ans=0;
		val[0]=1;
		for(int i=1;i<=n;i++) inv[i]=qpow(i,mod-2),val[i]=val[i-1]*i;
		for(int i=1;i<=n;i++){
			if(pb[i]){
				int cnt=0;
				for(int j=1;j<=n;j++){
					if(c[j]<i) cnt++;
				}
				
			}
		}
	}
	return 0;
}//明年出题出简单点好吗
//luogu @f_XY 
