#include <bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][3];
int x[100005],y[100005],z[100005],xs,ys,zs;
bool cmp1(int q,int p){
	return a[q][0]<a[p][0];
}
bool cmp2(int q,int p){
	return a[q][1]<a[p][1];
}
bool cmp3(int q,int p){
	return a[q][2]<a[p][2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		memset(x,-1,sizeof(x));
		memset(y,-1,sizeof(y));
		memset(z,-1,sizeof(z));
		xs=0,ys=0,zs=0;
		cin >> n;
		int mid=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				x[xs++]=i;
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				y[ys++]=i;
			}
			else{
				z[zs++]=i;
			}
		}
		sort(x,x+xs,cmp1);
		bool w=false;
		if(xs-1>mid){
			w=true;
			for(int i=0;i<xs-1-mid;i++){
				if(a[x[i]][1]>=a[x[i]][2]){
					y[ys++]=i;
					x[i]=-1;
				}
				else{
					z[zs++]=i;
					x[i]=-1;
				}
			}
		}
		sort(y,y+ys,cmp2);
		if(ys-1>mid&&!w){
			w=true;
			for(int i=0;i<ys-1-mid;i++){
				if(a[y[i]][0]>=a[y[i]][2]){
					x[xs++]=i;
					y[i]=-1;
				}
				else{
					z[zs++]=i;
					y[i]=-1;
				}
			}
		}
		sort(z,z+zs,cmp3);
		if(zs-1>mid&&!w){
			w=true;
			for(int i=0;i<zs-1-mid;i++){
				if(a[z[i]][0]>=a[y[i]][1]){
					x[xs++]=i;
					z[i]=-1;
				}
				else{
					y[ys++]=i;
					z[i]=-1;
				}
			}
		}
		int ans=0;
		for(int i=0;i<max(xs,max(ys,zs));i++){
			if(x[i]!=-1){
				ans+=a[x[i]][0];
			}
			if(y[i]!=-1){
				ans+=a[y[i]][1];
			}
			if(z[i]!=-1){
				ans+=a[z[i]][2];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
