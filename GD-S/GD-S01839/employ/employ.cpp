#include<bits/stdc++.h>
#define int long long
#define pop __builtin_popcount
using namespace std;
const int N=505,M=20,p=998244353;
int n,m,tot,fac[N],b[N],k[M],cnt[N],f[1<<18][M],dp[1<<18];
char a[N];
void add(int &x,int y){x=(x+y)%p;}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>(a+1);
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cnt[b[i]]++;
	for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%p;
	if(n<=18){
		f[0][0]=1;
		for(int s=1;s<1<<n;s++){
			int x=pop(s);
			for(int i=0;i<=x;i++){
				for(int j=1;j<=n;j++)if(s>>(j-1)&1){
					if(a[x]=='1'&&x-i<b[j]){
						if(i>0)add(f[s][i],f[s-(1<<(j-1))][i-1]);
					}
					if(a[x]=='0'||x-i-1>=b[j])add(f[s][i],f[s-(1<<(j-1))][i]);
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++)add(ans,f[(1<<n)-1][i]);
		cout<<ans;
		return 0;
	}
	if(m==1){
		int ans=1,c=0;
		for(int i=1;i<=n;i++)if(a[i]=='1'){
			if(cnt[i-1]-c>0)ans=ans*(cnt[i-1]-c)%p;
			else ans=0;
			c++;
		}
		ans=ans*fac[n-c]%p;
		cout<<((fac[n]-ans)%p+p)%p;
		return 0;
	}
	if(m==n){
		int ans=fac[n];
		for(int i=1;i<=n;i++)if(a[i]=='0'||b[i]==0)ans=0;
		cout<<ans;
		return 0;
	}
}
