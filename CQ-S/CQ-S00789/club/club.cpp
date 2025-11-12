#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int z;
struct hh{
	int c[5];
	int maxid,midid,minid;
}a[100005];
int rs[5],syg[5];
bool cmp(hh x,hh y){
	if(x.c[x.maxid]!=y.c[y.maxid])return x.c[x.maxid]>y.c[y.maxid];
	if(x.c[x.midid]!=y.c[y.midid])return x.c[x.midid]>y.c[y.midid];
	return x.c[x.minid]>y.c[y.minid];
}
int hh(){
	z=0;
	rs[1]=rs[2]=rs[3]=0;
	syg[1]=syg[2]=syg[3]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].c[1]>>a[i].c[2]>>a[i].c[3];
		if(a[i].c[1]>a[i].c[2]&&a[i].c[1]>a[i].c[3]){
			a[i].maxid=1;
			if(a[i].c[2]>a[i].c[3]){a[i].midid=2,a[i].minid=3;}
			else{a[i].midid=3,a[i].minid=2;}
		}else if(a[i].c[2]>a[i].c[1]&&a[i].c[2]>a[i].c[3]){
			a[i].maxid=2;
			if(a[i].c[1]>a[i].c[3]){a[i].midid=1,a[i].minid=3;}
			else{a[i].midid=3,a[i].minid=1;
			}
		}else{
			a[i].maxid=3;
			if(a[i].c[1]>a[i].c[2]){a[i].midid=1,a[i].minid=2;}
			else{a[i].midid=2,a[i].minid=1;}
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		int y=a[i].maxid,yy=a[i].midid,yyy=a[i].minid;
		if(rs[y]<n/2){
			rs[y]++;
			z+=a[i].c[y];
			syg[y]=i;
		}else{
			if(a[syg[y]].c[y]+a[i].c[yy]<a[syg[y]].c[a[syg[y]].midid]+a[i].c[y]&&rs[a[syg[y]].midid]<n/2){
				z-=a[syg[y]].c[y];
				z+=a[i].c[y]+a[syg[y]].c[a[syg[y]].midid];
				syg[a[syg[y]].midid]=syg[y];
				syg[y]=i;
				rs[a[syg[y]].midid]++;
			}
			else{
				if(rs[yy]<n/2){
					rs[yy]++;
					z+=a[i].c[yy];
					syg[yy]=i;
				}else{
					if(a[syg[yy]].c[yy]+a[i].c[yyy]<a[syg[yy]].c[a[syg[yy]].midid]+a[i].c[yy]&&rs[a[syg[yy]].midid]<n/2){
						z-=a[syg[yy]].c[yy]+a[i].c[yy]+a[syg[yy]].c[a[syg[yy]].midid];
						syg[a[syg[yy]].midid]=syg[yy];
						syg[yy]=i;
						rs[a[syg[yy]].midid]++;
					}else{
						rs[yyy]++;
						z+=a[i].c[yyy];
						syg[yyy]=i;
					}
				}
			}
		}
	}
	return z;
}
bool f=1,ff=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cout<<hh()<<'\n';	
	}
	return 0;
}
