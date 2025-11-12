#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define N 510
const int mod=998244353;
int n,m,a[N],ans,p[N],bk[N],A[N],f[N][N],g[N][N];
string s;
bool vis[N];
void dfs(int x){
	if(x==n){
		int nums=0,del=0;
		rep(i,1,n){
			if(s[i]=='0'){del++;continue;}
			if(del>=a[p[i]]){del++;}else{nums++;}
		}
		if(nums>=m){ans++;}
		return;
	}
	rep(i,1,n){
		if(!vis[i]){
			p[x+1]=i;
			vis[i]=1;
			dfs(x+1);
			p[x+1]=0;
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=" "+s;rep(i,1,n){cin>>a[i];}
	int nums=0;
	rep(i,1,n){if(s[i]=='1'){nums++;}}
	if(nums<m){cout<<0;return 0;}
	if(n<=10){
		dfs(0);
		cout<<ans%mod;
		return 0;
	}
	if(n==m){
		bool fl=0;
		rep(i,1,n){
			if(a[i]==0||s[i]=='0'){
				fl=1;
				break;
			}
		}
		if(fl){
			cout<<0;
			return 0;
		}
		else{
			ans=1;
			rep(i,1,n){ans=ans*i%mod;}
			cout<<ans;
			return 0;
		}
		return 0;
	}
	A[0]=1;
	rep(i,1,n){A[i]=A[i-1]*i%mod;}
	rep(i,1,n){bk[a[i]]++;}
	rep(i,1,n){bk[i]+=bk[i-1];}
	if(m==1){
		rep(i,1,n){
			int pre=0,tim=1,nums=0,ss=0;
			rep(j,1,a[i]-1){
				if(s[j]=='1'){
					tim=tim*max(0ll,bk[j-1]-nums)%mod;
					nums++;
				}
				if(s[j+1]=='1'){
					ss=(ss+A[n-1-nums]*tim%mod)%mod;
				}
			}
			if(s[1]=='1'&&a[i]>=1){
				ss=(ss+A[n-1])%mod;
			}
			ans=(ans+ss)%mod;
		}
		cout<<ans;
		return 0;
	}
	bool flg=0;
	rep(i,1,n){if(s[i]=='0'){
		flg=1;
	}
	}
	if(!flg){
		sort(a+1,a+n+1);
		f[0][0]=1;
		rep(i,0,n-1){
			rep(j,0,n){
				rep(k,0,n){
					g[j][k]=f[j][k];
					f[j][k]=0;
				}
			}
			rep(j,0,n){
				rep(k,0,n){
					f[j][k+1]=(f[j][k+1]+g[j][k]*max(0ll,bk[k]-k)%mod)%mod;
					if(a[i+1]>k){
						f[a[i+1]][k]=(f[a[i+1]][k]+g[j][k])%mod;
					}
				}
			}
		}
		rep(j,0,n){
			rep(k,0,n-m){
				ans=(ans+f[j][k])%mod;
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=18){
		dfs(0);
		cout<<ans%mod;
		return 0;
	}
	cout<<0;
	return 0;
}
