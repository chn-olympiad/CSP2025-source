#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int x,y,z;
	int mx;
	int mxnum;
}a[100005];
bool cmp1(node xx,node yy){
	return xx.mx>yy.mx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			int xx,yy,zz,x2,y2,z2;
			cin>>xx>>yy>>zz;
			cin>>x2>>y2>>z2;
			int a1=max(xx+y2,xx+z2),a2=max(yy+x2,yy+z2),a3=max(zz+x2,zz+y2);
			int ans=max(max(a1,a2),a3);
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].mx=max(max(a[i].x,a[i].y),a[i].z);
			if(a[i].mx==a[i].x){
				a[i].x=-1;
				a[i].mxnum=1;
			}
			else if(a[i].mx==a[i].y){
				a[i].y=-1;
				a[i].mxnum=2;
			}
			else if(a[i].mx==a[i].z){
				a[i].z=-1;
				a[i].mxnum=3;
			}
		}
		int ans=0;
		int vis[5]={0,0,0,0};
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(vis[a[i].mxnum]<(n/2)){
				vis[a[i].mxnum]+=1;
				ans+=a[i].mx;
				a[i].mx=-1;
				a[i].x=-1;
				a[i].y=-1;
				a[i].z=-1;
			}
			else{
				a[i].mx=max(max(a[i].x,a[i].y),a[i].z);
				if(a[i].mx==a[i].x){
					a[i].x=-1;
					a[i].mxnum=1;
				}
				else if(a[i].mx==a[i].y){
					a[i].y=-1;
					a[i].mxnum=2;
				}
				else if(a[i].mx==a[i].z){
					a[i].z=-1;
					a[i].mxnum=3;
				}
				sort(a+1+i,a+n+1,cmp1);
				i-=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
