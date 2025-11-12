#include<bits/stdc++.h>
const int mx=INT_MIN;
using namespace std;
int t,n[6];
struct my{
	int m1,m2,m3;
	bool z=0;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n[i];
		int r=n[i]/2;
		int c1=0,c2=0,c3=0,x1=mx,x2=mx,x3=mx,xx,xy,xz,dmx=0,ans=0;
		for(int j=0;j<n[i];j++){
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
			x1=max(x1,a[i].m1);
			xx=i;
			x2=max(x2,a[i].m2);
			xy=i;
			x3=max(x3,a[i].m3);
			xz=i;
		}
		if(xx==xy&&xy==xz)  dmx=max(max(x1,x2),max(x2,x3));
		if(dmx==x1)  c1++;
		else if(dmx==x2)  c2++;
		else  c3++;
		for(int j=0;j<n[i];j++){
			if(dmx){
				ans+=dmx;
				a[xx].z=1;
				for(int k=0;k<n[i];k++){
					if(k==xx) continue;
					if(a[k].z==0){
						a[k].z=1;
						int wa=max(max(a[k].m1,a[k].m2),max(a[k].m2,a[k].m1));
						if(wa==a[k].m1&&c1<=r){
							c1++;
							ans+=wa;
						}else if(wa==a[k].m2&&c2<=r){
							c2++;
							ans+=wa;
						}else if(wa==a[k].m3&&c3<=r){
							c3++;
							ans+=wa;
						}
					} else continue;
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
