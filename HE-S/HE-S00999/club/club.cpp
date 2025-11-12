#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][4],dr[100005],x[100005],y[100005],z[100005],xx=0,yy=0,zz=0,ans=0;
bool cmd(long long v,long long u){
	return dr[v]>dr[u];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,xx=0,yy=0,zz=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			long long maxa=max(max(a[i][1],a[i][2]),a[i][3]);
			ans+=maxa;
			if(a[i][1]==maxa){
				if(a[i][2]>a[i][3])
					dr[i]=a[i][1]-a[i][2];
				else
					dr[i]=a[i][1]-a[i][3];
				xx++;
				x[xx]=i;
			}else if(a[i][2]==maxa){
				if(a[i][1]>a[i][3])
					dr[i]=a[i][2]-a[i][1];
				else
					dr[i]=a[i][2]-a[i][3];
				yy++;
				y[yy]=i;
			}else{
				if(a[i][2]>a[i][1]) dr[i]=a[i][3]-a[i][2];
				else dr[i]=a[i][3]-a[i][1];
				zz++;
				z[zz]=i;
			}
		}
		long long maxw=max(max(xx,yy),zz),maxn;
		if(maxw==xx) maxn=1;
		else if(maxw==yy) maxn=2;
		else maxn=3;
		if(maxw>n/2){
			if(maxn==1){
				sort(x+1,x+xx+1,cmd);
				for(;maxw>n/2;maxw--) ans-=dr[x[maxw]];
			}else if(maxn==2){
				sort(y+1,y+yy+1,cmd);
				for(;maxw>n/2;maxw--) ans-=dr[y[maxw]];
			}else{
				sort(z+1,z+zz+1,cmd);
				for(;maxw>n/2;maxw--) ans-=dr[z[maxw]];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}//Ô¤ÆÚµÃ·Ö 100 O(t(n+logn))
