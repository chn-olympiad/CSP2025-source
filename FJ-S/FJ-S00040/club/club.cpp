#include<bits/stdc++.h>
using namespace std;
int const N=1e5+10;
struct a{int id;int my;}x[10][N];
struct b{int id;int my;}y[10][N];
struct c{int id;int my;}z[10][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		int n;cin>>n;
		int mid=n/2,ans=0;
		int maxx=0;
		int cntx=0,cnty=0,cntz=0;
		int minnx=0x3f3f3f3f,minny=0x3f3f3f3f,minnz=0x3f3f3f3f;
		int flagx=0,flagy=0,flagz=0;
		for(int j=1;j<=n;j++){
			cin>>x[i][j].my>>y[i][j].my>>z[i][j].my;
			minnx=min(minnx,x[i][j].my);
			minny=min(minny,y[i][j].my);
			minnz=min(minnz,z[i][j].my);
			if(x[i][j].my>=y[i][j].my && x[i][j].my>=z[i][j].my){
				if(cntx<mid && y[i][j].my==0 && z[i][j].my==0){
					cntx++;ans+=x[i][j].my;x[i][j].id=1;continue;
				} 
				else if(cntx<mid) cntx++,ans+=x[i][j].my,x[i][j].id=1;
				else{
					for(int k=1;k<=j;k++){
						if(x[i][j].my>x[i][k].my && x[i][k].id && x[i][k].my==minnx) ans+=x[i][j].my-x[i][k].my;
					}
				} 
			} 
			else if(y[i][j].my>=x[i][j].my && y[i][j].my>=z[i][j].my){
				if(cnty<mid && x[i][j].my==0 && z[i][j].my==0){
					cnty++;ans+=y[i][j].my;y[i][j].id=1;continue;
				} 
				else if(cnty<mid) cnty++,ans+=y[i][j].my,y[i][j].id=1;
				else{
					for(int k=1;k<=j;k++){
						if(y[i][j].my>y[i][j-1].my && y[i][k].id && y[i][k].my==minny) ans+=y[i][j].my-y[i][k].my;
					}
				}
			}
			else{
				if(cntz<mid && x[i][j].my==0 && y[i][j].my==0){
					cntz++;ans+=z[i][j].my;z[i][j].id=1;continue;
				} 
				else if(cntz<mid) cntz++,ans+=z[i][j].my,z[i][j].id=1;
				else{
					for(int k=1;k<=j;k++){
						if(z[i][j].my>z[i][j-1].my && z[i][k].id && z[i][k].my==minnz) ans+=z[i][j].my-z[i][k].my;
					}
				}
			} 
		}
		if(n==2){
			maxx=max(x[i][1].my+y[i][2].my,x[i][1].my+z[i][2].my);
			maxx=max(maxx,y[i][1].my+x[i][2].my);
			maxx=max(maxx,y[i][1].my+z[i][2].my);
			maxx=max(maxx,z[i][1].my+x[i][2].my);
			maxx=max(maxx,z[i][1].my+y[i][2].my);
			ans=maxx;
		}
		if(n==4){
			maxx=max(maxx,x[i][1].my+x[i][2].my+y[i][3].my+y[i][4].my);
			maxx=max(maxx,x[i][1].my+x[i][2].my+y[i][3].my+z[i][4].my);
			maxx=max(maxx,x[i][1].my+x[i][2].my+y[i][4].my+z[i][3].my);
			maxx=max(maxx,x[i][1].my+x[i][2].my+z[i][3].my+z[i][4].my);
			maxx=max(maxx,x[i][1].my+x[i][3].my+y[i][2].my+y[i][4].my);
			maxx=max(maxx,x[i][1].my+x[i][3].my+y[i][2].my+z[i][4].my);
			maxx=max(maxx,x[i][1].my+x[i][3].my+y[i][4].my+z[i][2].my);
			maxx=max(maxx,x[i][1].my+x[i][3].my+z[i][2].my+z[i][4].my);
			maxx=max(maxx,x[i][1].my+x[i][4].my+y[i][2].my+y[i][3].my);
			maxx=max(maxx,x[i][1].my+x[i][4].my+y[i][2].my+z[i][3].my);
			maxx=max(maxx,x[i][1].my+x[i][4].my+y[i][3].my+z[i][2].my);
			maxx=max(maxx,x[i][1].my+x[i][4].my+z[i][2].my+z[i][3].my);
			ans=maxx;
		}
		cout<<ans<<endl;
	}
	return 0;
}
