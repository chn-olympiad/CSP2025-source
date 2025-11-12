#include<bits/stdc++.h>
#define ll long long
#define N 1000010
#define mod 998244353
using namespace std;
ll n,m,ans;
string s;
ll f[1<<19][20],c[21],o[21],co[1<<19];
ll q[N],p[N];
vector<ll>v[N];

ll ksm(ll x,ll y){
	ll rest=1;
	while(y){
		if(y&1)rest=(rest*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return rest;
}
ll cnt(ll x){
	ll i=0;
	while(x){
		i++;
		x=(x-1)&x;
	}
	return i;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll i,j,k,l,x,y,z;
	cin>>n>>m>>s;
	for(i=1;i<=n;i++)cin>>c[i];
	q[0]=p[0]=1;
	for(i=1;i<=n;i++)q[i]=(q[i-1]*i)%mod,p[i]=(p[i-1]*ksm(i,mod-2))%mod;
	if(m==n){
		x=0;
		for(i=0;i<n;i++)x=(s[i]-'0');
		if(x==n){
			for(i=1;i<=n;i++){
				if(c[i]==0){
					cout<<0<<"\n";
					return 0;
				}
			}
			cout<<q[n];
		}else cout<<"0\n";
		return 0;
	}
	if(n>=21){
		cout<<0<<"\n";
		return 0;
	}
	o[1]=1;
	for(i=2;i<=n;i++)o[i]=o[i-1]<<1;
	for(i=0;i<=((1<<n)-1);i++){
		co[i]=cnt(i);
		v[co[i]].push_back(i);
	}
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(k=0;k<=n;k++){
		for(l=0;l<v[k].size();l++){
			x=v[k][l];
			for(j=1;j<=n;j++){
				if(o[j]&x)continue;
				for(i=0;i<=k;i++){
//					cout<<f[x][i]<<" "<<s[k]<<" "<<c[j]<<"   ";
					if(s[k]=='1'&&i<c[j])f[x|o[j]][i]=(f[x|o[j]][i]+f[x][i])%mod;
					else f[x|o[j]][i+1]=(f[x|o[j]][i+1]+f[x][i])%mod;
				}
			}
		}
	}
	ans=0;
	for(i=0;i<=n-m;i++)ans+=(ans+f[(1<<n)-1][i])%mod;
	cout<<ans<<"\n";
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
