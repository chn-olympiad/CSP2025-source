#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y,z;
}a[1000006]; 
int v[1000006][4],vv[1000006][4],vvv[1000006][4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0,v1n=0,v2n=0,v3n=0;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				ans+=a[i].x;
				v1n++;
				v[v1n][1]=a[i].x;
				v[v1n][2]=a[i].y;
				v[v1n][3]=a[i].z;
			}if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				ans+=a[i].y;
				v2n++;
				vv[v2n][1]=a[i].x;
				vv[v2n][2]=a[i].y;
				vv[v2n][3]=a[i].z;
			}if(a[i].z>=a[i].y&&a[i].z>=a[i].x){
				ans+=a[i].z;
				v3n++;
				vvv[v3n][1]=a[i].x;
				vvv[v3n][2]=a[i].y;
				vvv[v3n][3]=a[i].z;
			}
		}
		if(v1n>n/2){
			for(int i = v1n;i>n/2;i--){
				int minn=999999999,minid,minid2;
				for(int j = 1;j<=v1n;j++){
					if(v[j][1]-v[j][2]<minn){
						minn=v[j][1]-v[j][2];
						minid=j;
						minid2=2;
					}
					if(v[j][1]-v[j][3]<minn){
						minn=v[j][1]-v[j][3];
						minid=j;
						minid2=3;
					}
				}
				if(minid2==2&&v2n<n/2){
					vv[++v2n][1]=v[minid][1];
					vv[v2n][2]=v[minid][2];
					vv[v2n][3]=v[minid][3];
					v[minid][1]=999999999999;
					v[minid][2]=-999999999999;
					v[minid][3]=-999999999999;
					ans-=minn;
				}
				if(minid2==3&&v3n<n/2){
					vvv[++v3n][1]=v[minid][1];
					vvv[v3n][2]=v[minid][2];
					vvv[v3n][3]=v[minid][3];
					v[minid][1]=999999999999;
					v[minid][2]=-999999999999;
					v[minid][3]=-999999999999;
					ans-=minn;
				}
			}
		}if(v2n>n/2){
			for(int i = v2n;i>n/2;i--){
				int minn=999999999,minid,minid2;
				for(int j = 1;j<=v2n;j++){
					if(vv[j][2]-vv[j][3]<minn){
						minn=vv[j][2]-vv[j][3];
						minid=j;
						minid2=3;
					}if(vv[j][2]-vv[j][1]<minn){
						minn=vv[j][2]-vv[j][1];
						minid=j;
						minid2=1;
					}
				}
				if(minid2==1&&v1n<n/2){
					v[++v2n][1]=vv[minid][1];
					v[v2n][2]=vv[minid][2];
					v[v2n][3]=vv[minid][3];
					vv[minid][1]=-999999999999;
					vv[minid][2]=999999999999;
					vv[minid][3]=-999999999999;
					ans-=minn;
				}
				if(minid2==3&&v3n<n/2){
					vvv[++v3n][1]=vv[minid][1];
					vvv[v3n][2]=vv[minid][2];
					vvv[v3n][3]=vv[minid][3];
					vv[minid][1]=-999999999999;
					vv[minid][2]=999999999999;
					vv[minid][3]=-999999999999;
					ans-=minn;
				}
			}
		}
		if(v3n>n/2){
			for(int i = v3n;i>n/2;i--){
				int minn=999999999,minid,minid2;
				for(int j = 1;j<=v3n;j++){
					if(vvv[j][3]-vvv[j][2]<minn){
						minn=vvv[j][3]-vvv[j][2];
						minid=j;
						minid2=2;
					}
					if(vvv[j][3]-vvv[j][1]<minn){
						minn=vvv[j][3]-vvv[j][1];
						minid=j;
						minid2=1;
					}
				}
				if(minid2==2&&v2n<n/2){
					vv[++v2n][1]=vvv[minid][1];
					vv[v2n][2]=vvv[minid][2];
					vv[v2n][3]=vvv[minid][3];
					vvv[minid][1]=-999999999999;
					vvv[minid][2]=-999999999999;
					vvv[minid][3]=999999999999;
					ans-=minn;
				}
				if(minid2==1&&v1n<n/2){
					v[++v1n][1]=vvv[minid][1];
					v[v1n][2]=vvv[minid][2];
					v[v1n][3]=vvv[minid][3];
					vvv[minid][1]=-999999999999;
					vvv[minid][2]=-999999999999;
					vvv[minid][3]=999999999999;
					ans-=minn;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
