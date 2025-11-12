#include<bits/stdc++.h>
using namespace std;
const int N=205;
int t,n,a[N][3],f[N/2][N/2][N/2];
struct Node{
	int c,x,y,z;
}g[N];
bool cmp(Node x,Node y){
	return x.c<y.c;
}
bool pd(){
	for(int i=1;i<=n;++i)if(a[i][2]!=0)return 0;
	return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(!pd()){
			for(int i=1;i<=n;++i){
				for(int j=0;j<=min(n/2,i);++j){
					for(int k=max(0,i-j-n/2);k<=min(n/2,i-j);++k){
						int l=i-j-k;
						f[j][k][l]=0;
						if(j!=0)f[j][k][l]=f[j-1][k][l]+a[i][0];
						if(k!=0)f[j][k][l]=max(f[j][k][l],f[j][k-1][l]+a[i][1]);
						if(l!=0)f[j][k][l]=max(f[j][k][l],f[j][k][l-1]+a[i][2]);
						if(i==n)ans=max(ans,f[j][k][l]);
					}
				}
			}
		} else {
			for(int i=1;i<=n;++i){
				g[i].x=a[i][0];
				g[i].y=a[i][1];
				g[i].z=a[i][2];
			}
			for(int i=1;i<=n;++i)g[i].c=g[i].x-g[i].y;
			sort(g+1,g+n+1,cmp);
			for(int i=1;i<=n/2;++i)ans+=g[i].y;
			for(int i=n/2+1;i<=n;++i)ans+=g[i].x;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

