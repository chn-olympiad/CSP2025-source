#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=998244353;
int n,m,c[505],ans,cnt,f[270005][20];
int jc[505];
string str;
int a[15],vis[15];
void dfs(int now){
	if(now==n+1){
		int cnt=0,res=0;
		for(int i=1;i<=n;i++){
//			cout<<a[i]<<" ";
			if(cnt>=c[a[i]]){
				cnt++;
				continue;
			}
			if(str[i]=='1'){
				res++;
			}
			else{
				cnt++;
			}
		}
//		cout<<res<<"\n";
		if(res>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
signed main()
{
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>str;
	str=(char)0+str;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(str[i]=='1'){
			cnt++;
		}
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(n<=10){
		dfs(1);
		cout<<ans<<"\n";
		return 0;
	}
	if(n<=18){
		ans=0;
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int s=0;s<(1<<n);s++){
				int x=__builtin_popcount(s);
				if(x!=i-1){
					continue;
				}
				for(int j=1;j<=n;j++){
					if(s&(1<<(j-1))){
						continue;
					}
					if(str[i]=='1'){
						for(int k=0;k<=x;k++){
							if(c[j]<=x-k){
								f[s^(1<<(j-1))][k]+=f[s][k];
								f[s^(1<<(j-1))][k]%=mod;
							}
							else{
								f[s^(1<<(j-1))][k+1]+=f[s][k];
								f[s^(1<<(j-1))][k+1]%=mod;
							}
						}
					}
					else{
						for(int k=0;k<=x;k++){
							f[s^(1<<(j-1))][k]+=f[s][k];
							f[s^(1<<(j-1))][k]%=mod;
						}
					}
				}
			}
		}
		for(int i=m;i<=n;i++){
			ans+=f[(1<<n)-1][i];
			ans%=mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	if(m==1){
		sort(c+1,c+n+1);
		int now=0,res=1,cnt=0;
		for(int i=1;i<=n;i++){
			if(str[i]=='1'){
				while(now<n&&c[now+1]<=i-1){
					now++;
				}
				res*=(now-cnt);
				res%=mod;
//				cout<<i<<" "<<now<<" "<<c[now]<<" "<<cnt<<"\n";
				cnt++;
			}
		}
		ans=jc[n]-res*jc[n-cnt]%mod;
		cout<<(ans%mod+mod)%mod;
		return 0;
	}
	if(m==n){
		ans=jc[n];
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				ans=0;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

