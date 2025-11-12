#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N =5E2+10,M = 5e2+10,MOD=998244353;

ll ans,n,m,c[N],a[N],cf[N],ton[N],f[510][510];
char s;


int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
/*
	for(int i=0;i<=10;i++) f[i][0]=1;
	for(int i=1;i<=10;i++){
		for(int j=1;j<=510;j++){
			f[i][j] = f[i-1][j]+f[i-1][j-1];	
		}
	}*/

	cin>>n>>m;
	ll fa=1;
	
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s=='1') cf[i]=0;
		else cf[i] = 1,fa=0;
	}
	a[1] = cf[1];
	for(int i=2;i<=n;i++) a[i] = a[i-1]+cf[i];
	
	for(int i=1;i<=n;i++) cin>>c[i],ton[c[i]]++;
	
	if(fa){
		ans=1;
		ll tmp=n;
		for(int i=1;i<=n;i++) if(c[i]==0) tmp--;
		for(int i=1;i<=tmp;i++) ans = (ans*i)%MOD;
		cout<<ans%MOD;
		return 0;
	}
	
	
	

	
	
	return 0;
}
