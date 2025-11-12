#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
char ch;
int n,m,ans,C[505][505],f[505][505][505],cnt[505],a[505],b[505],sumc[505],sufc[505],suma[505][2],fac[505];
void add(int &a,int b){
	a+=b;
	if(a<0) a+=mod;
	if(a>=mod) a-=mod;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			add(C[i][j],C[i-1][j-1]);
			add(C[i][j],C[i-1][j]);
		}
	}
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>ch;
		a[i]=ch-'0';
		suma[i][a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		suma[i][0]+=suma[i-1][0];
		suma[i][1]+=suma[i-1][1];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		cnt[b[i]]++;
	}
	sumc[0]=cnt[0];
	for(int i=1;i<=n;i++){
		sumc[i]=sumc[i-1]+cnt[i];
	}
	for(int i=n;i>=0;i--){
		sufc[i]=sufc[i+1]+cnt[i];
	}
	f[1][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=n;k++){
				if(!f[i][j][k]) continue;
				if(a[i]==0){
					for(int a=0;a<=cnt[j+1];a++){
						//cout<<"qwq"<<i<<' '<<j<<' '<<k<<' '<<a<<'\n';
						if(k<=sumc[j]) add(f[i+1][j+1][k+a+1],f[i][j][k]*C[cnt[j+1]][a]%mod*fac[a]%mod*C[i-j][a]%mod*(sumc[j]-k)%mod);
						add(f[i+1][j+1][k+a],f[i][j][k]*C[cnt[j+1]][a]%mod*fac[a]%mod*C[i-j][a]%mod);
					}
				}else{
					for(int a=0;a<=cnt[j+1];a++){
						//cout<<"qwq"<<i<<' '<<j<<' '<<k<<' '<<a<<'\n';
						if(k<=sumc[j]) add(f[i+1][j+1][k+a+1],f[i][j][k]*C[cnt[j+1]][a]%mod*fac[a]%mod*C[i-j][a]%mod*(sumc[j]-k)%mod);
						//cout<<"ok"<<C[cnt[j+1]][a]<<' '<<fac[a]<<' '<<C[i-j][a]<<' '<<sumc[j]<<' '<<k<<'\n'; 
					}
					add(f[i+1][j][k],f[i][j][k]);
				}
				//if(f[i][j][k]) cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<'\n';
			}
		}
	}
	for(int i=n-m;i>=0;i--){
		add(ans,f[n+1][i][sumc[i]]);
	}
	cout<<ans;
	return 0;
}
