#include<bits/stdc++.h>
using namespace std;
const int N=505,P=998244353;
using ll=long long;
inline ll ksm(ll a,int b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%P;
		a=a*a%P,b>>=1;
	}
	return res;
}
inline void Add(int &u,int v){u+=v;(u>=P)&&(u-=P);}
int n,m;
int a[N],ton[N];
string s;
int f[N][N][N];
ll fac[N],inv[N];
int suf[N];
inline ll C(int n,int m){return fac[n]*inv[m]%P*inv[n-m]%P;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%P;
	inv[n]=ksm(fac[n],P-2);
	for(int i=n-1;i>=1;i--)inv[i]=inv[i+1]*(i+1)%P;
	cin>>s;
	for(int i=1;i<=n;i++)a[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		x++;
		ton[x]++;
	}
	for(int i=n+1;i>=0;i--)suf[i]=ton[i]+suf[i+1]; 
	for(int i=0;i<=n-m;i++){
		f[n+1][i][0]=1;
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				int v=f[i+1][j][k];
//				if(v)cerr<<i+1<<" "<<j<<" "<<k<<" "<<v<<"??\n";
				if(!v)continue;
				if(a[i]==0){
					if(j)
					for(int l=0;l<=ton[j+1]&&l<=k+1;l++){
//						cerr<<i+1<<" "<<j<<" "<<k<<" "<<l<<" "<<C(ton[j+1],l)*C(k+1,l)%P<<"????\n";
						Add(f[i][j-1][k+1-l],C(ton[j+1],l)*C(k+1,l)%P*v%P);
					}
				}
				else{
					int num=n-i-k;
					Add(f[i][j][k],1ll*v*(suf[j+2]-num)%P);
//					cerr<<suf[j+2]-num<<"!!!\n";
					if(j)
					for(int l=0;l<=ton[j+1]&&l<=k;l++){
//						cerr<<i+1<<" "<<j<<" "<<k<<" "<<l<<" "<<C(ton[j+1],l)*C(k,l)%P<<"????\n";
						Add(f[i][j-1][k+1-l],C(ton[j+1],l)*C(k,l)*v%P);
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++){
		ans+=f[1][0][i]*fac[i]%P;
	}
	cout<<ans%P<<"\n";	
	return 0;
}