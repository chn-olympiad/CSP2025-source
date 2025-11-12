#include<bits/stdc++.h>
#define ll long long
#define N 505
using namespace std;
int n,m,a[N],b[N],k,M;
ll mod=998244353;
ll f[19][19][262150];//第i天，j人弃权 
void solve1(){
	if(k>n-m){
		printf("0");
		return;
	}
	ll ans=1;
	
}
void solve(){
	f[0][0][0]=1;
	M=(1<<n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<M;k++){
				for(int l=0;l<n;l++){
					int c=(1<<l);
					if(c&k)continue;
					if(b[i]==0){
						f[i][j][c+k]=(f[i][j][c+k]+f[i-1][j-1][k])%mod;
					}
					else{
						if(j>=a[l])
							f[i][j][c+k]=(f[i][j][c+k]+f[i-1][j-1][k])%mod;
						else
							f[i][j][c+k]=(f[i][j][c+k]+f[i-1][j][k])%mod;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int j=0;j<=n-m;j++){
		ans=(ans+f[n][j][M-1])%mod;
	}
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	cin>>n>>m>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		b[i+1]=s[i]-'0';
		cnt+=b[i+1];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)k++;
	}
	if(cnt==n)solve1();
	else solve();
	
	return 0;
}
