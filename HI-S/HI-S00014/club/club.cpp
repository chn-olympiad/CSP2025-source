#include<bits/stdc++.h>
#define float double
#define AC return 0
using namespace std;
int n,A,B,C,dp[205][205][205];
struct wh{
	int a,b,c;
}f[100005];
bool cmp(wh x,wh y) {
	return x.a>y.a;
}
int num(wh h) {
	if(h.a==max(h.a,max(h.b,h.c))) return 1;
	if(h.b==max(h.a,max(h.b,h.c))) return 2;
	if(h.c==max(h.a,max(h.b,h.c))) return 3;
}
int main() {
 	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int j=n/2;j>=0;j--) 
				for(int k=n/2;k>=0;k--) 
					for(int l=n/2;l>=0;l--) dp[j][k][l]=0;
		bool b[n+5]={};
		int maxa=0,maxb=0,maxc=0;
		for(int i=1;i<=n;i++) {
			cin>>f[i].a>>f[i].b>>f[i].c;
			maxa=max(maxa,f[i].a);
			maxb=max(maxb,f[i].b);
			maxc=max(maxc,f[i].c);
		}
		if(maxb==0&&maxc==0) {
			sort(f+1,f+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=f[i].a;
			cout<<ans<<endl;
			continue;
		}
		else if(maxc==0) {
			for(int i=1;i<=n;i++) {
				for(int j=n/2;j>=0;j--) {
					for(int k=n/2;k>=0;k--) {
						int r,t,y,l=0;
						if(j==0) r=0;
						else r=dp[j-1][k][l]+f[i].a;
						if(k==0) t=0;
						else t=dp[j][k-1][l]+f[i].b;
						if(l==0) y=0;
						else y=dp[j][k][l-1]+f[i].c;
						dp[j][k][l]=max(r,max(t,y));
						//cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<dp[j][k][l]<<endl;
					}
				}
			}
			cout<<dp[n/2][n/2][0]<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) {
			for(int j=n/2;j>=0;j--) {
				for(int k=n/2;k>=0;k--) {
					for(int l=n/2;l>=0;l--) {
						int r,t,y;
						if(j==0) r=0;
						else r=dp[j-1][k][l]+f[i].a;
						if(k==0) t=0;
						else t=dp[j][k-1][l]+f[i].b;
						if(l==0) y=0;
						else y=dp[j][k][l-1]+f[i].c;
						dp[j][k][l]=max(r,max(t,y));
						//cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<dp[j][k][l]<<endl;
					}
				}
			}
		}
		cout<<dp[n/2][n/2][n/2]<<endl;
	} 
	AC;
}
