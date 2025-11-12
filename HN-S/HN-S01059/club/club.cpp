#include<bits/stdc++.h>
using namespace std;
#define int long long

struct db{
	int x,y,w,idx,idy,idw;
}a[100010];
map<int,int> p;
bool cmp(db a,db b){
	if(a.x==b.x){
		if(a.y==b.y){
			return a.w>b.w;
		}
		return a.y>b.y;
	}
	return a.x>b.x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i].x>>a[i].y>>a[i].w;
			a[i].idx=1;
			a[i].idy=2;
			a[i].idw=3;
			if(a[i].x>a[i].y && a[i].x>a[i].w){
				if(a[i].y<a[i].w){
					int t=a[i].y;
					int id=a[i].idy;
					a[i].y=a[i].w;
					a[i].idy=a[i].idw;
					a[i].w=t;
					a[i].idw=id;
				}
			}else if(a[i].x<a[i].y && a[i].y>a[i].w){
				int t=a[i].x;
				int id=a[i].idx;
				a[i].x=a[i].y;
				a[i].idx=a[i].idy;
				a[i].y=t;
				a[i].idy=id;
				if(a[i].y<a[i].w){
					t=a[i].y;
					id=a[i].idy;
					a[i].y=a[i].w;
					a[i].idy=a[i].idw;
					a[i].w=t;
					a[i].idw=id;
				}
			}else if(a[i].x<a[i].w && a[i].y<a[i].w){
				int t=a[i].x;
				int id=a[i].idx;
				a[i].x=a[i].w;
				a[i].idx=a[i].idw;
				a[i].w=t;
				a[i].idw=id;
				if(a[i].y<a[i].w){
					int t=a[i].y;
					int id=a[i].idy;
					a[i].y=a[i].w;
					a[i].idy=a[i].idw;
					a[i].w=t;
					a[i].idw=id;
				}
			}
		}
		sort(a+1,a+n+1,cmp); 
		if(n==1){
			if(a[1].idx!=a[2].idx){
				cout<<a[1].x+a[2].x<<"\n";
				continue;
			}else{
				cout<<max(a[1].y+a[2].x,a[2].y+a[1].x)<<"\n";
				continue;
			}
		}
		int ans=0;
		for(int i=1; i<=n; i++){
			if(p[a[i].idx]<n/2){
				if(a[i+1].x+a[i].y>=a[i].x && a[i].idx==a[i+1].idx){
					ans+=a[i].y;
					p[a[i].idy]++;
				}else{
					p[a[i].idx]++;
					ans+=a[i].x;
				}
			}else if(p[a[i].idx]>n/2){
				if(p[a[i].idy]<n/2){
					if(a[i+1].y+a[i].w>a[i].y && a[i].idy==a[i+1].idy){
						ans+=a[i].w;
						p[a[i].idw]++;
					}else{
						p[a[i].idy]++;
						ans+=a[i].y;
					}
				}else if(p[a[i].idy]>n/2){
					p[a[i].idw]++;
					ans+=a[i].w;
				}
			}
		}
		cout<<ans<<"\n";
		p[1]=0;
		p[2]=0;
		p[3]=0;
	}
	return 0;
} 
