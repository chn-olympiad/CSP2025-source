#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=550,mo=998244353;
int n,m;
int c[N],v[N];
ll ans,f[1<<19][22],fac[N],inv[N],g[N][2*N];
string s;
void sub1(){
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int tot=__builtin_popcount(i);
		// if(tot!=t) continue;
		for(int j=1;j<=n;j++){
			if(((i>>j-1)&1)==0){
				for(int k=0;k<=tot;k++){
					if(!v[tot+1]){
						f[i^(1<<j-1)][k]+=f[i][k];
					}else {
						if(tot-k<c[j]){
							f[i^(1<<j-1)][k+1]+=f[i][k];
						}else f[i^(1<<j-1)][k]+=f[i][k];
					}
					f[i^(1<<j-1)][k]%=mo;
				}
			}
		}
	}
	for(int i=m;i<=n;i++){
		// cout<<i<<" "<<f[n][(1<<n)-1][i]<<'\n';
		ans+=f[(1<<n)-1][i];
		ans%=mo;
	}
	cout<<ans<<'\n';
}
ll C(int x,int y){
	if(x<y) return 0;
	return fac[x]*inv[y]%mo*inv[x-y]%mo;
}
void sub2(){
	sort(c+1,c+1+n);
	ll sum=1;
	int fl=1;
	g[0][0]=1;
	for(int i=1;i<=n;i++){
		int cnt=0;
		while(c[fl]<i&&fl<=n) fl++,cnt++;
		for(int j=0;j<=n;j++){
			if(v[i]){
				g[i][j+cnt-1]+=(j+cnt)*g[i-1][j];
				g[i][j+cnt-1]%=mo;
			}else{
				g[i][j+cnt-1]+=(j+cnt)*g[i-1][j];

			}
		}
	}
	cout<<(fac[n]+mo-sum)%mo<<'\n';
}
void sub3(){
	for(int i=1;i<=n;i++){
		if(c[i]==0||v[i]==0){
			cout<<"0\n";
			return ;
		}
	}
	cout<<fac[n]<<'\n';
}
ll po(ll x,int y){
	ll z=1;
	while(y){
		if(y%2) z=z*x%mo;
		x=x*x%mo;
		y/=2;
	}
	return z;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m>>s;
	fac[0]=1;
	s="$"+s;
	for(int i=1;i<=n;i++) v[i]=s[i]-'0';
	for(int i=1;i<=n;i++){
		cin>>c[i];
		fac[i]=fac[i-1]*i%mo;
	}
	inv[n]=po(fac[n],mo-2);
	for(int i=n-1;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mo;
	}
	if(n<=18) sub1();
	else if(m==1) sub2();
	else if(m==n) sub3();
	return 0;
}