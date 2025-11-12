#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005;
int t,n;
ll ans=0;
ll a[N][5];
ll f[2][N][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);
		ans=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;++i)
		  scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		int lim=n/2;
		for(int i=0;i<n;++i){
			for(int j=0;j<=min(i,lim)+1;++j)
		      for(int k=0;k<=min(i,lim)+1;++k)
		        f[(i+1)&1][j][k]=0;
			for(int j=0;j<=min(i,lim);++j)
		      for(int k=0;k<=min(i,lim);++k){
		    	if(j<lim)  f[(i+1)&1][j+1][k]=max(f[(i+1)&1][j+1][k],f[i&1][j][k]+a[i+1][1]);
		    	if(k<lim)  f[(i+1)&1][j][k+1]=max(f[(i+1)&1][j][k+1],f[i&1][j][k]+a[i+1][2]);
		    	if(i-j-k<lim)  f[(i+1)&1][j][k]=max(f[(i+1)&1][j][k],f[i&1][j][k]+a[i+1][3]);
			  }
		}
		for(int i=0;i<=lim;++i)
		  for(int j=0;j<=lim;++j)
		    if(n-i-j<=lim)
		      ans=max(ans,f[n&1][i][j]);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/