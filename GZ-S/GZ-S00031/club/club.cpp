//余诗琪 GZ-S00031 贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=1e5+5;
ll n,a[mx][4],ans,grp1[mx],grp2[mx],grp3[mx],siz1,siz2,siz3,idx1,idx2,idx3;
int tt;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>tt;
	while(tt--) {
		ans=siz1=siz2=siz3=idx1=idx2=idx3=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++)
				cin>>a[i][j];
			int u=a[i][1],v=a[i][2],w=a[i][3];
			if(u>=v&&u>=w) {
				siz1++;
				ans+=u;
				grp1[++idx1]=u-max(v,w);
			} else if(v>=u&&v>=w) {
				siz2++;
				ans+=v;
				grp2[++idx2]=v-max(u,w);
			} else if(w>=u&&w>=v){
				siz3++;
				ans+=w;
				grp3[++idx3]=w-max(v,u);
			}
		}
		if(siz1>n/2) {
			sort(grp1+1,grp1+idx1+1);
			for(int i=1; i<=siz1-n/2; i++) ans-=grp1[i];
		} else if(siz2>n/2) {
			sort(grp2+1,grp2+idx2+1);
			for(int i=1; i<=siz2-n/2; i++) ans-=grp2[i];
		} else if(siz3>n/2) {
			sort(grp3+1,grp3+idx3+1);
			for(int i=1; i<=siz3-n/2; i++) ans-=grp3[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
