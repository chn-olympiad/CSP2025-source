#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rd(){int x=0;char ch=getchar();while(!isdigit(ch)) ch=getchar();while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x;}
const int N=510,M=998244353;
int n,m,c[N],sum[N];
vector<int> p,q;
ll jc[N],inv[N],ans,f[N][N];
char s[N];

ll ksm(ll a,ll b=M-2){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%M;
		a=a*a%M,b>>=1;
	}
	return ans;
}

ll C(int n,int m){
	if(n<m||m<0) return 0;
	return jc[n]*inv[m]%M*inv[n-m]%M;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd(),m=rd();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='1') p.push_back(i);
	for(int i=1;i<=n;i++) c[i]=rd(),sum[c[i]]++;
	for(int i=n;i;i--) sum[i]+=sum[i+1];
	jc[0]=inv[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%M;
	inv[n]=ksm(jc[n]);
	for(int i=n-1;i;i--) inv[i]=inv[i+1]*(i+1)%M;
	if(n==m){
		if((int)p.size()==n&&sum[1]==n) printf("%lld",jc[n]);
		else printf("0");
		return 0;
	}
	if((int)p.size()==n){
		if(sum[1]>=m) printf("%lld",jc[n]);
		else printf("0");
		return 0;
	}
	int k=(int)p.size();
	for(int S=1;S<(1<<k);S++){
		int x=__builtin_popcount(S);
		if(x<m) continue;
		q.clear();
		q.push_back(0);
		for(int i=0;i<k;i++) if((S>>i)&1) q.push_back(p[i]);
		q.push_back(n+1);
		for(int i=1;i<=x;i++) q[i]=q[i]-i+1;
		for(int i=0;i<=x;i++) for(int j=0;j<=x;j++) f[i][j]=0;
		f[0][0]=1;
		for(int i=1;i<=x;i++) for(int j=0;j<=i;j++){
			for(int k=0;j+k<=i;k++){
				if(j+k==0) continue;
				f[i][j]=(f[i][j]+f[i-1][j+k-1]*C(j+k,k)%M*C(sum[q[i]]-sum[q[i+1]],k)%M*jc[k])%M;
			}
		}
//		ans=(ans+f[x][0])%M;
		ans=(ans+((x-m)&1?M-1:1)*f[x][0]%M*jc[n-x]%M)%M;
	}
	printf("%lld",ans);
	return 0;
}
/*
3 2
101
1 1 2
2


10 5
1101111011
6 0 4 2 1 2 5 4 3 3

2204128

*/
