#include<bits/stdc++.h>
#define fo(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
const int mod=998244353;
int a[5010],f[505][5][105][205],n;
int dg(int x,int t,int mx,int s){
	if(x>n)
		return t<3||mx<<1>=s;
	if(s>a[0]<<1)
		return 0;
	if(f[x][t][mx][s]==-1)
		f[x][t][mx][s]=(dg(x+1,min(3,t+1),max(mx,a[x]),s+a[x])+dg(x+1,t,mx,s))%mod;
	return f[x][t][mx][s];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int s=1;
	cin>>n;
	fo(i,1,n){
		cin>>a[i];
		s=(s<<1)%mod;
		a[0]=max(a[0],a[i]);
	}
	if(a[0]==1){
		cout<<(s-1-n-(n*(n-1ll)>>1)%mod+(mod<<1))%mod;
		return 0;
	}
	fo(i,1,n)
		fo(j,0,3)
			fo(k,0,a[0])
				fo(l,0,a[0]<<1)
					f[i][j][k][l]=-1;
	cout<<(s-dg(1,0,0,0)+mod)%mod;
	return 0;
}
