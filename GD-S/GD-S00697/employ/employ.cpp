#include<cstdio>
#include<algorithm>

#define gc() getchar()

using namespace std;

const int N=505,mod=998244353;

int qpow(int x,int y){
	int ans=1;
	while(y>0){
		if(y&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ans;
}
int res[N*2],inv[N*2];
int C(int x,int y){
	if(y<0||x<y)return 0;
	return 1ll*res[x]*inv[y]%mod*inv[x-y]%mod;
}

int n,m,a[N];
bool bz[N];
char ch;

int Ans;

namespace BF{
	const int S=(1<<18)+5;
	int dp[S][20],sm[S];
	bool ck(){return (n<=18);}
	void solve(){
		for(int i=0;i<(1<<n);i++)sm[i]=sm[i>>1]+(i&1);
		dp[0][0]=1;
		for(int s=0;s<(1<<n);s++){
			for(int j=1;j<=n;j++){
				if((s&(1<<(j-1)))!=0)continue;
				for(int i=0;i<=sm[s];i++){
					if(bz[sm[s]+1]&&i<a[j]){
						(dp[s|(1<<(j-1))][i]+=dp[s][i])%=mod;
					}
					else{
						(dp[s|(1<<(j-1))][i+1]+=dp[s][i])%=mod;
					}
				}
			}
		}
		for(int i=0;i<=n-m;i++)(Ans+=dp[(1<<n)-1][i])%=mod;
		printf("%d\n",(Ans%mod+mod)%mod);
		return;
	}
}

namespace MM1{
	bool ck(){return (m==1);}
	int Ans,sm[N],tmp,cnt;
	void solve(){
		for(int i=1;i<=n;i++){
			sm[a[i]]++;
		}
		for(int j=1;j<=n;j++)sm[j]+=sm[j-1];
		for(int i=1;i<=n;i++){
			if(!bz[i])continue;
			tmp=1;cnt=0;
			for(int j=1;j<i;j++){
				if(!bz[j])continue;
				tmp=1ll*tmp*max(sm[j-1]-cnt,0)%mod;
				cnt++;
			}
			cnt++;
			tmp=1ll*tmp*(n-sm[i-1])%mod*res[n-cnt]%mod;
			(Ans+=tmp)%=mod;
		}
		printf("%d\n",(Ans%mod+mod)%mod);
		return;
	}
}

namespace MN{
	bool ck(){return (m==n);}
	void solve(){
		for(int i=1;i<=n;i++){
			if(!bz[i]){
				printf("0\n");
				return;
			}
			if(a[i]==0){
				printf("0\n");
				return;
			}
		}
		printf("%d\n",(res[n]%mod+mod)%mod);
		return;
	}
}

namespace subA{
	bool ck(){
		for(int i=1;i<=n;i++){
			if(!bz[i])return 0;
		}
		return 1;
	}
	int dp[N][N],sm[N],now;
	void solve(){
		for(int i=1;i<=n;i++){
			sm[a[i]]++;
		}
		dp[0][sm[0]]=1;now=sm[0];
		for(int i=0;i<n;i++){
			for(int j=0;j<=n;j++){
				if(dp[i][j]==0)continue;
				for(int k=0;k<=sm[i+1];k++){
					int tmp=max(j-i,0);
					(dp[i+1][j+k]+=1ll*dp[i][j]*C(now-tmp+sm[i+1]-k,sm[i+1]-k)%mod*(k==0?1:C(tmp+k-1,k))%mod)%=mod;
				}
			}
			now+=sm[i+1];
		}
		for(int j=0;j<=n-m;j++)(Ans+=dp[n][j])%=mod;
		for(int i=0;i<=n;i++)Ans=1ll*Ans*res[sm[i]]%mod;
		printf("%d\n",(Ans%mod+mod)%mod);
		return;
	}
}

namespace subB{
	int s,w[N];
	bool ck(){
		s=0;
		for(int i=1;i<=n;i++){
			if(bz[i]){
				w[++s]=i;
			}
		}
		return (s<=18);
	}
	int Ans,sm[N],tmp,pr[N],cnt;
	bool tg[N];
	void dfs(int x){
		if(x>s){
			cnt=0;
			for(int i=1;i<=s;i++){
				pr[i]=w[i]-1-cnt;
				if(tg[i])cnt++;
			}
			if(cnt<m)return;
			tmp=1;
			cnt=0;
			for(int i=1;i<=s;i++){
				if(tg[i])continue;
				tmp=1ll*tmp*max(sm[pr[i]]-cnt,0)%mod;
				cnt++;
			}
			cnt=0;
			for(int i=s;i>=1;i--){
				if(!tg[i])continue;
				tmp=1ll*tmp*max(n-sm[pr[i]]-cnt,0)%mod;
				cnt++;
			}
			(Ans+=tmp)%=mod;
			return;
		}
		tg[x]=1;
		dfs(x+1);
		tg[x]=0;
		dfs(x+1);
		return;
	}
	void solve(){
		for(int i=1;i<=n;i++){
			sm[a[i]]++;
		}
		for(int i=1;i<=n;i++)sm[i]+=sm[i-1];
		dfs(1);
		Ans=1ll*Ans*res[n-s]%mod;
		printf("%d\n",(Ans%mod+mod)%mod);
		return;
	}
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		ch=gc();
		while(ch!='0'&&ch!='1')ch=gc();
		bz[i]=(ch=='1');
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	res[0]=1;
	for(int i=1;i<=n*2;i++)res[i]=1ll*res[i-1]*i%mod;
	inv[n*2]=qpow(res[n*2],mod-2);
	for(int i=n*2;i>=1;i--)inv[i-1]=1ll*inv[i]*i%mod;
	
	if(0);
	else if(BF::ck())BF::solve();
	else if(MM1::ck())MM1::solve();
	else if(MN::ck())MN::solve();
	else if(subA::ck())subA::solve();
	else if(subB::ck())subB::solve();
	
	return 0;
}
