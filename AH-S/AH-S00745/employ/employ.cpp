#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,a[N],b[N],f[1<<18][19];
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void work0(){
	f[0][0]=1;
	for(int S=0;S<(1<<n)-1;S++){
		int p=__builtin_popcount(S);
		for(int i=0;i<=p;i++)
			if(f[S][i]){
				for(int j=0;j<=n;j++)
					if(!(S&(1<<j))){
						if(!a[p+1]||p-i>=b[j])add(f[S|(1<<j)][i],f[S][i]);
							else add(f[S|(1<<j)][i+1],f[S][i]);
					}
			}
	}
	int ans=0;
	for(int i=m;i<=n;i++)add(ans,f[(1<<n)-1][i]);
	cout<<ans;
}
void work2(){
	for(int i=1;i<=n;i++)if(!a[i]||!b[i-1]){cout<<0;return;}
	int ans=1;
	for(int i=1;i<=n;i++)ans=1ll*ans*i%mod;
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
	for(int i=0;i<n;i++)scanf("%d",&b[i]);
	if(n<=18){work0();return 0;}
	if(m==n){work2();return 0;}
	int ans=1;
	for(int i=1;i<=n;i++)ans=1ll*ans*i%mod;
	cout<<ans;
}