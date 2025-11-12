#include<bits/stdc++.h>
#define int long long
using namespace std;
long long const mod=998244353;
int n,m;
string s;
int c[505];
long long f[505][505][2];
int q[505];
int ans[505];
bool bz[505];
int z=0;
void dfs(int x){
	if(x>n){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='0'){++cnt;
			}
			else{
				if(c[ans[i]]<=cnt){
					cnt++;
				}
			}
		}
		if(n-cnt>=m){
		++z;
	/*	for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
		cout<<endl;	*/
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(!bz[i]){
			bz[i]=1;
			ans[x]=i;
			dfs(x+1);
			bz[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s; 
	s=" "+s;
	int cn=0;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		q[i]=q[i-1]+(s[i]=='0');
		cn+=(c[i]==0);
	}
	if(n<=10){
		dfs(1);
		cout<<z;
		return 0;
	}
	if(s[1]=='1'){
		f[1][0][1]=n-cn;
		f[1][1][0]=cn;
	}
	else f[1][1][0]=n;
	for(int i=2;i<=n;++i){
		for(int j=q[i];j<=i;++j){
			if(s[i]=='0'){
				if(j-1>=0)
				f[i][j][0]=f[i-1][j-1][0]*(n-(j-1))%mod+f[i-1][j-1][1]*(n-(j-1))%mod;
				f[i][j][0]%=mod;
			}
			else{
				long long cnt=0;
				for(int k=1;k<=n;++k){
					if(c[k]<=j-1)cnt++;
				}
				if(j-1>=0&&cnt-(j-1)>=0)
				f[i][j][0]=f[i-1][j-1][0]*(cnt-(j-1))%mod+f[i-1][j-1][1]*(cnt-(j-1));
				if(j-1>=0&&((n-cnt)-(i-j))>=0)
				f[i][j][1]=f[i-1][j-1][0]*((n-cnt)-(i-j))%mod+f[i-1][j-1][1]*((n-cnt)-(i-j))%mod;
				f[i][j][1]%=mod;
				f[i][j][0]%=mod;
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=n-m;++i){
		ans+=f[n][i][0]+f[n][i][1];
		ans%=mod;
	}
	cout<<ans;
	return 0;
}

