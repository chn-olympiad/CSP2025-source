#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=998244353;

int n,m;
int a[510],b[510];
LL f[(1<<18)+5][20];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char cc;cin>>cc;b[i]=cc-'0';
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=18){
		f[0][0]=1;
		for(int i=1;i<(1<<n);i++){
			int cnt=0;
			for(int j=0;j<n;j++) if(i&(1<<j)) cnt++;
			for(int j=1;j<=n;j++){
				if(!(i&(1<<(j-1)))) continue;
				for(int k=0;k<cnt;k++){
					if(b[cnt]&&k<a[j]) f[i][k]=(f[i][k]+f[i-(1<<(j-1))][k])%MOD;
					else f[i][k+1]=(f[i][k+1]+f[i-(1<<(j-1))][k])%MOD;
				}
			}
		}
		LL ans=0;
		for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%MOD;
		cout<<ans<<"\n";
		return 0;
	}
	if(m==1){
		LL ans=1,tmp=1;
		for(int i=1;i<=n;i++) tmp=tmp*i%MOD;
		int now=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i]==0){cnt++;continue;}
			while(now+1<=n&&a[now+1]<=i-1) now++;
			ans=ans*(now-(i-1-cnt))%MOD;
		}
		for(int i=1;i<=cnt;i++) ans=ans*i%MOD;
		cout<<(tmp-ans+MOD)%MOD<<"\n";
		return 0;
	}
	if(m==n){
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=b[i];
		if(cnt!=n){cout<<"0\n";return 0;}
		for(int i=1;i<=n;i++)
			if(a[i]==0){cout<<"0\n";return 0;}
		LL ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%MOD;
		cout<<ans<<"\n";
		return 0;
	}
	
	return 0;
}
