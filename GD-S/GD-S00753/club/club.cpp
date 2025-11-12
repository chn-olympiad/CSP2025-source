#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T;
int n;
struct edge{
	int x,y,z;
	int px,py,pz;
	int cx,cy,cz;
	int vis;
}a[N];
int t[4];
int ans;
bool cmp1(edge a,edge b){
	if(a.px==b.px)return a.cx>b.cx;
	else return a.px<b.px;
}
bool cmp2(edge a,edge b){
	if(a.py==b.py)return a.cy>b.cy;
	else return a.py<b.py;
}
bool cmp3(edge a,edge b){
	if(a.pz==b.pz)return a.cz>b.cz;
	else return a.pz<b.pz;
}
void wyz(int q){
	int xx=a[q].x,yy=a[q].y,zz=a[q].z;
	if(xx>=yy&&xx>=zz){
		a[q].px=1;
		if(yy>=zz)a[q].py=2,a[q].pz=3;
		else a[q].py=3,a[q].pz=2;
	}else if(yy>=xx&&yy>=zz){
		if(xx>=zz)a[q].px=2,a[q].pz=3;
		else a[q].px=3,a[q].pz=2;
		a[q].py=1;
	}else{
		if(xx>=yy)a[q].px=2,a[q].py=3;
		else a[q].px=3,a[q].py=2;
		a[q].pz=1;
	}
}
int sumx,sumy,sumz; 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			wyz(i);
			a[i].cx=a[i].x-a[i].y;
			a[i].cy=a[i].y-a[i].z;
			a[i].cz=a[i].z-a[i].x;
			a[i].vis=0;
		}
		sort(a+1,a+n+1,cmp1);
		sumx=0,sumy=0,sumz=0;
		ans=0;
		for(register int i=1;i<=n;i++){
			if(a[i].px!=1){
				break;
			}
			if(sumx==n/2){
				if(a[i].py==2){
					a[i].py=1;		
				}else{
					a[i].pz=1;
				}
			}else{
				ans+=a[i].x;
				a[i].vis=1;
				sumx++;
			}
		}
		sort(a+1,a+n+1,cmp2);
		for(register int i=1;i<=n;i++){
			if(a[i].vis)continue;
			if(a[i].py!=1){
				break;
			}
			if(sumy==n/2){
				if(a[i].pz==2){
					a[i].pz=1;
				}else{
					a[i].px=1;
				}
			}else{
				ans+=a[i].y;
				a[i].vis=1;
				sumy++;
			}
		}
		sort(a+1,a+n+1,cmp3);
		for(register int i=1;i<=n;i++){
			if(a[i].vis)continue;
			if(a[i].pz!=1){
				if(a[i].px<a[i].py){
					ans+=a[i].x;
				}else{
					if(sumy<n/2)ans+=a[i].y;
					else ans+=a[i].x;
				}
			}
			if(sumz==n/2){
				if(a[i].px<a[i].py){
					ans+=a[i].x;
				}else{
					ans+=a[i].y;
				}
			}else{
				ans+=a[i].z;
				sumz++;
			}
		}
		cout<<ans<<'\n';
	} 
} 
