#\
i\
n\
c\
l\
u\
d\
e\
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
#define int long long
using namespace std;

const int mod=998244353;
int n,m,ans,c[501],fac[5001],cnnt[501],dp[300001][21];
bool vs[11];
string s;
void init(){
	fac[0]=1;
	for(int i=1;i<=5000;i++)fac[i]=(fac[i-1]*i)%mod;
}
void dfs(int dep,int fq){
	if(fq>n-m)return; 
	if(dep>n){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vs[i])continue;
		vs[i]=true;
		int tfq=fq;
		if(fq>=c[i]||s[dep]=='0')tfq++;
//		cout<<"I:"<<i<<" TFQ:"<<tfq<<" FQ:"<<fq<<"\n";
		dfs(dep+1,tfq);
		vs[i]=false;
	}
}

signed main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	init();
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)cnnt[c[i]]++;
	if(n<=10){
		dfs(1,0);
		cout<<ans;
		akioi;
	}
//	if(n<=18){
//		dp[0][0]=1;
//		for(int j=1;j<(1<<n);j++){
//			int ppc=__builtin_popcount(j);
////			cout<<ppc<<"\n";
//			for(int l=0;l<=n;l++){
//				for(int i=1;i<=n;i++){
//					if((j&(1<<(i-1)))==0)continue;
//					if(l<c[i]&&s[ppc]=='1'){
//						dp[j][l]+=dp[j-(1<<(i-1))][l];
//					}else{
//						if(l!=0)dp[j][l]+=dp[j-(1<<(i-1))][l-1];
//					}
//					dp[j][l]%=mod;
////					cout<<"PPC:"<<ppc<<" J:"<<j<<" L:"<<l<<" DP:"<<dp[j][l]<<"\n";
//				}
//			} 
//		}
//		int ans=0;
//		for(int i=1;i<=n-m;i++){
//			ans+=dp[(1<<n)-1][i];
//			ans%=mod;
//		}
////		for(int i=1;i<=n;i++)cout<<dp[(1<<n)-1][i]<<"\n";
//		cout<<ans;
//		akioi;
//	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0||s[i]=='0'){
				cout<<0;
				akioi;
			}
		}
		cout<<fac[n];
		akioi;
	}
//	if(m==1){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=c[i];j++){
//				int acnt=n;
//				ans=1;
//				for(int l=1;l<=j;l++){
//					acnt-=cnt[l-1];
//					ans*=acnt;
//					ans%=mod;
//				}
//			}
//		}
//		akioi;
//	}
	bool fg=true;
	for(int i=1;i<=n;i++)if(s[i]!='1')fg=false;
	if(fg){
		cout<<fac[n];
		akioi;
	}
//	if(fg==true){
//		int all=0;
//		for(int i=1;i<=n;i++){
//			if(c[i]!=0)all++;
//		}
//		akioi;
//	}
	cout<<0;
	akioi;
}
/*
3 2
101
1 1 2

3 2
000
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
