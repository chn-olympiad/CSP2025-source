#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,val[205][4],f[2][205][205][205],ans;
void solve(){
	ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) scanf("%lld",&val[i][j]);
	}
	for(int i=0;i<=n/2;i++){
		for(int a=0;a<=n/2;a++){
			for(int b=0;b<=n/2;b++) f[0][i][a][b]=0,f[1][i][a][b]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			for(int a=0;a<=min(i,n/2);a++){
				for(int b=0;b<=min(i,n/2);b++){
					int opt1=i%2,opt2,c=i-a-b;
					if(opt1) opt2=0;
					else opt2=1;
					if(c<=0) break;
					if(c>n/2) continue;
					if(j==1){
						f[opt1][c][a][b]=max(f[opt1][c][a][b],max(f[opt2][c][a][b],f[opt2][c-1][a][b]+val[i][1]));
//						if(c==2) cout<<a<<' '<<b<<' '<<f[opt1][c][a][b]<<'\n';
					}
					else if(j==2){
						f[opt1][a][c][b]=max(f[opt1][a][c][b],max(f[opt2][a][c][b],f[opt2][a][c-1][b]+val[i][2]));
//						cout<<i<<' '<<a<<' '<<c<<' '<<b<<' '<<f[a][c][b]<<'\n';
					}
					else{
						f[opt1][a][b][c]=max(f[opt1][a][b][c],max(f[opt2][a][b][c],f[opt2][a][b][c-1]+val[i][3]));
					}
				}
			}
		}
		for(int a=0;a<=min(i,n/2);a++){
			for(int b=0;b<=min(i,n/2);b++){
				int c=i+1-a-b;
				if(c<0) continue;
				int opt1=i%2,opt2;
				if(opt1) opt2=0;
				else opt2=1;
				f[opt2][a][b][c]=0,f[opt2][a][c][b]=0,f[opt2][c][a][b]=0;
			}
		}
//		cout<<i<<' '<<f[i%2][1][0][1]<<'\n';
	}
	for(int i=0;i<=n/2;i++){
		for(int a=0;a<=n/2;a++){
			if(i+a<=n&&n-i-a<=n/2) ans=max(ans,f[0][i][a][n-i-a]);
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--) solve();
	return 0;
}
