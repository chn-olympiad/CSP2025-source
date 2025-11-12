#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=510,mod=998244353;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int C[N][N],jc[N];
int n,m,cnt[N],f[N][N],g[N][N],s[N];
char ch[N];
void work(int c,int j,int k,int res){
	for(int x=0;x<=min(cnt[j],c);x++)add(g[j][k+x],1ll*res*C[cnt[j]][x]%mod*jc[x]%mod*C[c][x]%mod);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>ch;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		cnt[x]++;
	} 
	s[0]=cnt[0];
	for(int i=1;i<=n;i++)s[i]=s[i-1]+cnt[i];
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*1ll*i%mod;
	f[0][0]=1;
	for(int i=0;i<n;i++){
		memset(g,0,sizeof(g));
		if(ch[i]=='1'){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++){
					int w=f[j][k];
					if(!w)continue;
					{
						add(g[j][k],f[j][k]);
					}//选用 c[x]>j 
					{
						if(s[j]-k>0)work(i-k,j+1,k+1,1ll*w*(s[j]-k)%mod);
					}//拒绝 c[x]<=j
				}
			}
		}else{
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++){
					
					int w=f[j][k];
					if(!w)continue;
					{
						work(i-k+1,j+1,k,w);
					}//拒绝 c[x]>j
					{
						if(s[j]-k>0)work(i-k,j+1,k+1,1ll*w*(s[j]-k)%mod);
					}//拒绝 c[x]<=j
				}
			}
		}
		swap(f,g);
//		printf("## %d\n",i+1);
//		for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)if(f[j][k])printf("f[%d][%d]=%d\n",j,k,f[j][k]);
//		puts("");
	}
	int ans=0;
	for(int j=0;j<=n-m;j++){
		add(ans,1ll*f[j][s[j]]*jc[n-s[j]]%mod);
	}
	cout<<ans<<endl;
}
//f[i][j][k]表示前i个位置，有j个拒绝，c[x]<=j的有k个被用过的方案数。 
