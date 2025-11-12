#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int S=(1<<18)+5;
const int mod=998244353;
int n,m,p,res,ans,a[N],f[S][25];
char c[N];
bool flag;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,c+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(m==n){
		flag=1;
		for(int i=1;i<=n;i++) if(c[i]=='0') flag=0;
		for(int i=1;i<=n;i++) if(a[i]==0) flag=0;
		if(flag){
			ans=1;
			for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
			printf("%d",ans);
		}
		else printf("0");
	}
	else if(m==1){
		sort(a+1,a+n+1);
		res=ans=1;
		for(int i=1,j=0;i<=n;i++) if(c[i]=='1'){
			p++;
			while(j<n&&a[j+1]<=i-1) j++;
			res=1ll*res*max(j-p+1,0)%mod;
		}
		for(int i=1;i<=n-p;i++) res=1ll*res*i%mod;
		for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
		printf("%d",(ans-res+mod)%mod);
	}
	else{
		f[0][0]=1;
		for(int s=1;s<1<<n;s++){
			p=0;
			for(int i=1;i<=n;i++) if(s&(1<<i-1)) p++;
			for(int i=1;i<=n;i++) if(s&(1<<i-1)){
				for(int j=0;j<=n;j++){
					if(j>=a[i]||c[p]=='0') f[s][j+1]=(f[s][j+1]+f[s^(1<<i-1)][j])%mod;
					else f[s][j]=(f[s][j]+f[s^(1<<i-1)][j])%mod;
				}
			}
		}
		for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%mod;
		printf("%d",ans);
	}
	return 0;
}
