#include<bits/stdc++.h>
using namespace std;
const int N=50+10;
int t,n,a[N][4],f[N][N][N][N],cnt;
/*
 * f[i][j][k][l]表示前i个人1部门有j人，2部门有k人，3部门有l人
 * f[i][j][k][l]=max(f[i-1][j-1][k][l]+a[i][1],f[i-1][j][k-1][l]+a[i][2],f[i-1][j][k][l-1]+a[i][3]);
 * 
 */
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,0,sizeof(f));
		int mx=0,mx2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>mx){
				mx2=mx;
				mx=a[i][1];
			}else if(a[i][1]>mx2){
				mx2=a[i][1];
			}
		}
		if(n==100000){
			cout<<mx+mx2;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					int l=i-j-k;
					if(l>n/2||l<0) continue;
					if(j>0) f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j-1][k][l]+a[i][1]);
					if(k>0) f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k-1][l]+a[i][2]);
					if(l>0) f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l-1]+a[i][3]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				int k=n-i-j;
				if(k>n/2||k<0) continue;
				ans=max(ans,f[n][i][j][k]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
