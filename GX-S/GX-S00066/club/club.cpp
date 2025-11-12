#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define il inline
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define Fr(i,a,b) for(int i=a;i>=b;i--)
const int N=1e5+5;
int n,a[N][5],f[202][202][202],ans,fg,d[N],w[N];
il void sol(){
	cin>>n; ans=fg=0;
	fr(i,1,n) cin>>a[i][1]>>a[i][2]>>a[i][3],fg=(a[i][3]!=0)?(1):(fg);
	if(!fg){
		fr(i,1,n) ans+=a[i][2],w[i]=a[i][1]-a[i][2];
		fr(i,1,n) d[i]=-2e9-1;
		fr(i,1,n) Fr(j,n/2,1)
		    d[j]=max(d[j],d[j-1]+w[i]);
		cout<<ans+d[n/2]<<endl;
		return;
	}
	fr(i,0,n) fr(j,0,n/2) fr(k,0,n/2) f[i][j][k]=-2e9-1;
	f[0][0][0]=0;
	fr(i,1,n) fr(j,0,n/2) fr(k,0,n/2){
	    if(j>0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
	    if(k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
	    if(i-j-k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
	 } fr(j,0,n/2) fr(k,0,n/2) if(n-j-k<=n/2) ans=max(ans,f[n][j][k]);
	 cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t; while(t--) sol();
	return 0;
}
