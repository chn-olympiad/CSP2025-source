#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n;
int a[N][5];
long long f[205][205][205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int x;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		memset(f,0,sizeof(f));
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					int m=i+j+k;
					if(i!=0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[m][1]);
					if(j!=0)f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[m][2]);
					if(k!=0)f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[m][3]);
				}
			}
		}
		long long ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				int k=n-i-j;
				if(k>n/2)continue;
				ans=max(ans,f[i][j][k]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
