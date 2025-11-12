#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],f[N][N],C[N][N],jc[N],nw,tr;
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%lld%lld%s",&n,&m,s+1);
	jc[0]=1;
	for(int i=1;i<=n;i++){
		int x;scanf("%lld",&x);
		if(x>0)c[x-1]++;
		jc[i]=jc[i-1]*i%mod,tr+=s[i]=='1';
	}
	for(int i=n;i>=0;i--)
		c[i]+=c[i+1];
	for(int i=0;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(int i=m;i<=tr;i++)
		f[0][i]=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			nw++;
			for(int j=nw;j>0;j--){
				for(int k=max(0ll,m-j);j+k<=tr;k++){
					int p=c[i-j]-k;
					if(p<=0||f[j-1][k+1]==0)continue;
					f[j][k]=(f[j][k]+f[j-1][k+1]*p)%mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=m;i<=tr;i++)
		cout<<f[i][0]*jc[n-i]%mod<<' ';
	for(int o=tr;o>=m;o--){
		f[o][0]=f[o][0]*jc[n-o]%mod;
		for(int i=o+1;i<=tr;i++)
			f[o][0]=(f[o][0]-f[i][0]*C[i][o])%mod;
		ans=(ans+f[o][0])%mod;
		cout<<f[o][0]<<endl;
	}
	printf("%lld\n",ans);
	
	return 0;
} 
