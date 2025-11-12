#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,M=110;
int T,n,a[N][3],f1[M][M][M],f2[M][M][M],x[N];
void solve1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++) cin>>a[i][j];
	}
	memset(f1,0,sizeof(f1));memset(f2,0,sizeof(f2));
	f1[1][0][0]=a[1][0],f1[0][1][0]=a[1][1],f1[0][0][1]=a[1][2];
	for(int l=2;l<=n/2;l++){
		for(int i=0;i<=min(l,n/2);i++){
			for(int j=0;j+i<=min(l,n/2);j++){
				int k=l-i-j;
				int t1=0,t2=0,t3=0;
				if(i-1>=0) t1=f1[i-1][j][k]+a[l][0];
				if(j-1>=0) t2=f1[i][j-1][k]+a[l][1];
				if(k-1>=0) t3=f1[i][j][k-1]+a[l][2];
				f1[i][j][k]=max(f1[i][j][k],max({t1,t2,t3}));
			} 
		}
	}
	f2[1][0][0]=a[n/2+1][0],f2[0][1][0]=a[n/2+1][1],f2[0][0][1]=a[n/2+1][2];
	for(int l=n/2+2;l<=n;l++){
		for(int i=0;i<=min(l-n/2,n/2);i++){
			for(int j=0;j+i<=min(l-n/2,n/2);j++){
				int k=l-n/2-i-j;
				int t1=0,t2=0,t3=0;
				if(i-1>=0) t1=f2[i-1][j][k]+a[l][0];
				if(j-1>=0) t2=f2[i][j-1][k]+a[l][1];
				if(k-1>=0) t3=f2[i][j][k-1]+a[l][2];
				f2[i][j][k]=max(f2[i][j][k],max({t1,t2,t3}));
			} 
		}
	}
	for(int i=0;i<=n/2;i++){
		for(int j=0;i+j<=n/2;j++){
			int k=n/2-i-j;
			for(int l=0;l<=n/2-i;l++){
				for(int r=0;l+r<=n/2&&r<=n/2-j;r++){
					int p=n/2-l-r;
					if(k+p>n/2) continue;
					ans=max(ans,f1[i][j][k]+f2[l][r][p]);
				}
			}
		}
	}
	cout<<ans<<'\n';
}
void solve2(){
	for(int i=1;i<=n;i++){
		int z1,z2;
		cin>>x[i]>>z1>>z2;
	}
	int ans=0;
	sort(x+1,x+n+1,greater<int>());
	for(int i=1;i<=n/2;i++) ans+=x[i];
	cout<<ans<<'\n';
}
void solve(){
	cin>>n;
	if(n<=200) solve1();
	else solve2();
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--) solve();
	return 0;
}
