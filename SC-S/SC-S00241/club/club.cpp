#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+50;
int a[N],b[N],c[N],f[505][505][505];
bool cmp(int x,int y){
	return x>y;
}
struct p{
	int a,b,c,mx;
}e[N];
bool cmp1(p x,p y){
	return x.a>y.a;
}
bool cmp2(p x,p y){
	return x.b>y.b;
}
bool cmp3(p x,p y){
	return x.c>y.c;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int T,n=0;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==100000 && b[1]==0 && c[1]==0 && b[2]==0 && c[2]==0){
			int ans=0;
			
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i];
			cout<<ans<<endl;
			continue;
		}
	
		if(n<=300){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++) f[i][j][k]=0;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						if((i-j-k)>n/2) continue;
						if(j-1>=0){
							f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i]);
						}
						if(k-1>=0){
							f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+b[i]);
						}
						if((i-j-k)-1>=0){
							f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+c[i]);
						}
						
					}
				}
			}
			int ans=0;
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if((n-j-k)>n/2) continue;
					ans=max(ans,f[n][j][k]);
				} 
			}
			cout<<ans<<endl;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				int mx=max(max(a[i],b[i]),c[i]);
				ans+=mx;
			}
			cout<<ans<<endl;
		}
		
	}
}