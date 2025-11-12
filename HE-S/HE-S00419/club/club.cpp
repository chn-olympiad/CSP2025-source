#include<bits/stdc++.h>
using namespace std;
const int N=10;
int t,n,ans,a[100005][3],f[N][N][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n,ans=0;
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=0;i<=n/2;i++) for(int j=0;j<=n/2;j++) for(int k=0;k<=n/2;k++){
			if(i+j+k>n) continue;
			if(i>0) f[i%N][j%N][k%N]=max(f[(i-1)%N][j%N][k%N]+a[i+j+k][0],f[i%N][j%N][k%N]);
			if(j>0) f[i%N][j%N][k%N]=max(f[i%N][(j-1)%N][k%N]+a[i+j+k][1],f[i%N][j%N][k%N]);
			if(k>0) f[i%N][j%N][k%N]=max(f[i%N][j%N][(k-1)%N]+a[i+j+k][2],f[i%N][j%N][k%N]);
			if(i+j+k==n) ans=max(ans,f[i%N][j%N][k%N]);
		}
		cout<<ans<<endl;
	}
}
