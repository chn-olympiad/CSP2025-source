//rp++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
const int K = 6e2+5;
int f[K][K][K],a[N][3];
int n,t,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		f[1][0][0]=a[1][0];
		f[0][1][0]=a[1][1];
		f[0][0][1]=a[1][2];
		for(int x=2;x<=n;x++){
			for(int i=0;i<=n/2;i++){
				if(i>x) continue;
				for(int j=0;j<=n/2;j++){
					if(i+j>x) continue;
					for(int k=0;k<=n/2;k++){
						if(i+j+k!=x) continue;
						if(i) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[x][0]);
						if(j) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[x][1]);
						if(k) f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[x][2]);
						ans=max(ans,f[i][j][k]);
					}
				}
			}
		}
		cout<<ans<<"\n";
		ans=0;
		for(int i=0;i<=n/2;i++)
			for(int j=0;j<=n/2;j++)
				for(int k=0;k<=n/2;k++)
					f[i][j][k]=0;
	}
	return 0;
}
