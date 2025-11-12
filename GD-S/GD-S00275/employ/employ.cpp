/*#include<bits/stdc++.h>
using namespace std;
mt19937 rd(time(0));
const int N=505,mod=998244353;
int n,m,t[N],C[N][N],fac[N];char ch[N];
void qm(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int qa(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int f[N][N][N];
int main(){C[0][0]=fac[0]=1;
	for(int i=1;i<N;i++){C[i][0]=1,fac[i]=1ll*fac[i-1]*i%mod;
		for(int j=1;j<=i;j++)C[i][j]=qa(C[i-1][j-1],C[i-1][j]);
	}
	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",ch+1);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),t[x]++;
	for(int i=1;i<=n;i++)t[i]+=t[i-1];
	f[0][0][0]=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)for(int k=0,v=0;k<=i;k++)if(v=f[i-1][j][k]){ 
			int res=t[j]-(cnt-k);
			cout<<" "<<i<<" "<<j<<" "<<k<<" "<<res<<" "<<f[i-1][j][k]<<endl;
			if(ch[i]=='1')qm(f[i][j+1][k],1ll*res*v%mod);
			else qm(f[i][j+1][k],v);
		}
		for(int j=0;j<=cnt;j++)for(int k=1;k<=i;k++){
			int res=t[j];
			if(i-j>0)res-=t[j-1];
			for(int x=1;x<=min(res,k);x++)
			qm(f[i][j][k-x],1ll*f[i][j][k]*C[res][x]%mod*fac[x]%mod);
		}
		if(ch[i]=='1'){
			for(int j=0;j<=n;j++)for(int k=0;k<=i;k++)qm(f[i][j][k+1],f[i-1][j][k]);
			cnt+=ch[i]=='1';
		}
		for(int j=0;j<=n;j++)for(int k=0;k<=i;k++)if(f[i][j][k])cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
		cout<<endl;
	}
	int ans=0;
	for(int i=0;i<=n;i++)for(int k=0;k<=n;k++){
		if(n-i<m)continue ;
		int res=t[n]-t[i];
		cout<<n<<" "<<i<<" "<<k<<" "<<f[n][i][k]<<" "<<res<<endl;
		qm(ans,f[n][i][k]*C[res][k]%mod*fac[k]%mod);
	}
	printf("%d\n",1ll*fac[n-cnt]*ans%mod);
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
mt19937 rd(time(0));
const int N=505,mod=998244353;
int n,m,t[N],C[N][N],fac[N];char ch[N];
void qm(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int qa(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int f[1<<20][20],a[N];
int main(){C[0][0]=fac[0]=1;
	for(int i=1;i<N;i++){C[i][0]=1,fac[i]=1ll*fac[i-1]*i%mod;
		for(int j=1;j<=i;j++)C[i][j]=qa(C[i-1][j-1],C[i-1][j]);
	}
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",ch+1);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),t[x]++,a[i]=x;
	if(m==n){
		for(int i=1;i<=n;i++)if(ch[i]=='0')return puts("0"),0;
		for(int i=1;i<=n;i++)if(a[i]==0)return puts("0"),0;
		puts("1");
		return 0;
	}
	for(int i=1;i<=n;i++)t[i]+=t[i-1];
	f[0][0]=1;
	int tmp=(1<<n)-1,ans=0;
	for(int s=0;s<tmp;s++){
		for(int j=0;j<=n;j++)if(f[s][j]){
			for(int x=0;x<n;x++)if(!((s>>x)&1))qm(f[s|(1<<x)][j+(ch[__builtin_popcount(s)+1]=='1'&&a[x+1]>__builtin_popcount(s)-j)],f[s][j]);
		}
	}
	for(int i=m;i<=n;i++)qm(ans,f[tmp][i]);
	printf("%d\n",ans);
	return 0;
}
 

