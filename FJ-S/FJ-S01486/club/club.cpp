#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,ans,a,b,c,vis[100005],x[100005][5],m,kf,kt,v;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ans=a=b=c=0;
		memset(vis,0,sizeof(vis));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++) scanf("%lld",&x[i][j]);
		for(int i=1;i<=n;i++){
			m=max(x[i][1],max(x[i][2],x[i][3]));
			if(m==x[i][1]&&a!=n/2){
				a++;
				ans+=m;
				vis[i]=1;
				continue;
			}
			if(m==x[i][2]&&b!=n/2){
				b++;
				ans+=m;
				vis[i]=2;
				continue;
			}
			if(m==x[i][3]&&c!=n/2){
				c++;
				ans+=m;
				vis[i]=3;
				continue;
			}
			if(m==x[i][1]){
				if(x[i][2]>x[i][3]){
					kf=i,kt=2,v=x[i][2];
				}else{
					kf=i,kt=3,v=x[i][3];
				}
				for(int j=i-1;j>=1;j--){
					if(vis[j]==1){
						if(x[i][1]-x[j][1]+x[j][2]>v&&b!=n/2){
							kf=j,kt=2,v=x[i][1]-x[j][1]+x[j][2];
						}
						if(x[i][1]-x[j][1]+x[j][3]>v&&c!=n/2){
							kf=j,kt=3,v=x[i][1]-x[j][1]+x[j][3];
						}
					}
				}
				vis[i]=1;
				vis[kf]=kt;
				ans+=v;
				if(kt==2) b++;
				if(kt==3) c++;
			}
			if(m==x[i][2]){
				if(x[i][1]>x[i][3]){
					kf=i,kt=1,v=x[i][1];
				}else{
					kf=i,kt=3,v=x[i][3];
				}
				for(int j=i-1;j>=1;j--){
					if(vis[j]==2){
						if(x[i][2]-x[j][2]+x[j][1]>v&&a!=n/2){
							kf=j,kt=1,v=x[i][2]-x[j][2]+x[j][1];
						}
						if(x[i][2]-x[j][2]+x[j][3]>v&&c!=n/2){
							kf=j,kt=3,v=x[i][2]-x[j][2]+x[j][3];
						}
					}
				}
				vis[i]=2;
				vis[kf]=kt;
				ans+=v;
				if(kt==1) a++;
				if(kt==3) c++;
			}
			if(m==x[i][3]){
				if(x[i][2]>x[i][1]){
					kf=i,kt=2,v=x[i][2];
				}else{
					kf=i,kt=1,v=x[i][1];
				}
				for(int j=i-1;j>=1;j--){
					if(vis[j]==3){
						if(x[i][3]-x[j][3]+x[j][2]>v&&b!=n/2){
							kf=j,kt=2,v=x[i][3]-x[j][3]+x[j][2];
						}
						if(x[i][3]-x[j][3]+x[j][1]>v&&a!=n/2){
							kf=j,kt=1,v=x[i][3]-x[j][3]+x[j][1];
						}
					}
				}
				vis[i]=3;
				vis[kf]=kt;
				ans+=v;
				if(kt==2) b++;
				if(kt==1) a++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
// 2025-11-01/16:48
//²ÝÉñµÄÐÅÍ½+1 Q-Q 
