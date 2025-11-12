#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,M=2e2+5;
ll t,n,a[N][4],sum,maxn,k[N],flaga,flagb,p[N],dp1[M][M][M];
bool cmp(ll a,ll b) {
	return a>b;
}
void dfs(ll x) {
	if(x==n+1) {
		maxn=max(maxn,sum);
		return;
	}
	for(int i=1;i<=3;i++) {
		if(k[i]<(n/2)) {
			k[i]++;
			sum+=a[x][i];
			dfs(x+1);
			k[i]--;
			sum-=a[x][i];
		} 
	}
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		flaga=flagb=1;
		maxn=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0) {
				flaga=0;
			}
			if(a[i][3]!=0) {
				flagb=0;
			}
		}
		if(n<=200) {
			memset(dp1,0,sizeof(dp1));
			for(int i=1;i<=(n/2);i++) {
				dp1[i][0][0]=a[i][1]+dp1[i-1][0][0];
				dp1[0][i][0]=a[i][2]+dp1[0][i-1][0];
				dp1[0][0][i]=a[i][3]+dp1[0][0][i-1];
			}
			for(int i=0;i<=(n/2);i++) {
				for(int j=0;j<=(n/2);j++) {
					for(int k=0;k<=(n/2);k++) {
						if(i!=0) {
							dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j][k]+a[i+j+k][1]);
						}
						if(j!=0) {
							dp1[i][j][k]=max(dp1[i][j][k],dp1[i][j-1][k]+a[i+j+k][2]);
						}
						if(k!=0) {
							dp1[i][j][k]=max(dp1[i][j][k],dp1[i][j][k-1]+a[i+j+k][3]);
						}
					}
				}
			}
			for(int i=0;i<=(n/2);i++) {
				for(int j=0;j<=(n/2);j++) {
					if(i+j>=(n/2)) {
						maxn=max(maxn,dp1[i][j][n-i-j]);
					}
				}
			}
			cout<<maxn<<'\n';
		} else if(flaga) {
			for(int i=1;i<=n;i++) {
				p[i]=a[i][1];
			}
			sort(p+1,p+n+1,cmp);
			for(int i=1;i<=(n/2);i++) {
				sum+=p[i];
			}
			cout<<sum<<'\n';
		} else if(flagb) {
			for(int i=1;i<=n;i++) {
				sum+=a[i][2];
				a[i][1]-=a[i][2];
			}
			for(int i=1;i<=n;i++) {
				p[i]=a[i][1];
			}
			sort(p+1,p+n+1,cmp);
			for(int i=1;i<=(n/2);i++) {
				sum+=p[i];
			}
			cout<<sum<<'\n';
		} else {
			
		}
	}
	return 0;
} 
