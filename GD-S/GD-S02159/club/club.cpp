#include<bits/stdc++.h>
using namespace std;
const int N=205,N2=2e5+10;
long long f[N][N][N];
int T;
int n;
int a[N][4];
int b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		bool op=0;
		long long ans=0,ans2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0)op=1;
		}
		if(op==1||n<=300){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n;j++){
					for(int k=0;k<=n;k++){
						f[i][j][k]=0;
				//		if(i-j-k>n/2)break;
						if(j!=0)f[i][j][k]=max(f[i-1][j-1][k]+a[i][1],f[i][j][k]);
						if(i-j-k!=0)f[i][j][k]=max(f[i-1][j][k]+a[i][3],f[i][j][k]);
						if(k!=0)f[i][j][k]=max(f[i-1][j][k-1]+a[i][2],f[i][j][k]);
						if(j<=n/2&&k<=n/2&&i-j-k<=n/2)ans=max(ans,f[i][j][k]);
						//cout<<i<<j<<k<<" "<<f[i][j][k]<<"\n";
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		else {
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--)ans2+=b[i];
			cout<<ans2<<"\n";
		}
	}
}
