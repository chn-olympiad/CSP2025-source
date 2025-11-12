#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int on[N],tw[N],th[N],n,cnt1,cnt2,cnt3;
struct P{
	int x,y,z;
}a[N];
void l(){
	memset(on,0,sizeof(on));
	memset(tw,0,sizeof(tw));
	memset(th,0,sizeof(th));
	cnt1=0,cnt2=0,cnt3=0;
	int m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		int maxs=max(a[i].x,max(a[i].y,a[i].z));
		if(a[i].x==maxs){
			if(cnt1<n/2) on[++cnt1]=i,m++;
			else{
				int c=0,p=-1;
				for(int j=1;j<=cnt1;j++){
					int nc=a[i].x-a[on[j]].x+max(a[on[j]].y,a[on[j]].z);
					if(nc>c){
						p=j;
						c=nc;
					}
				}
				int xc=max(a[i].y,a[i].z);
				if(xc>c) p=-1;
				if(p>-1){
					int y=a[on[p]].y,z=a[on[p]].z;
					if(y>z){
						tw[++cnt2]=on[p];
						m++;
					}else{
						th[++cnt3]=on[p];
						m++;
					}
					on[p]=i;
				}else{
					int y=a[i].y,z=a[i].z;
					if(y>z){
						tw[++cnt2]=i;
						m++;
					}else{
						th[++cnt3]=i;
						m++;
					}
				} 
			}
		} 
		else if(a[i].y==maxs){
			if(cnt2<n/2) tw[++cnt2]=i,m++;
			else{
				int c=0,p=-1;
				for(int j=1;j<=cnt2;j++){
					int nc=a[i].y-a[tw[j]].y+max(a[tw[j]].x,a[tw[j]].z);
					if(nc>c){
						p=j;
						c=nc;
					}
				}
				int xc=max(a[i].x,a[i].z);
				if(xc>c) p=-1;
				if(p>-1){
					int x=a[tw[p]].x,z=a[tw[p]].z;
					if(x>z){
						on[++cnt1]=tw[p];
						m++;
					}else{
						th[++cnt3]=tw[p];
						m++;
					}
					tw[p]=i;
				}else{
					int x=a[i].x,z=a[i].z;
					if(x>z){
						on[++cnt1]=i;
						m++;
					}else{
						th[++cnt3]=i;
						m++;
					}
				} 
			}
		} 
		else{
			if(cnt3<n/2) th[++cnt3]=i;
			else{
				int c=0,p=-1;
				for(int j=1;j<=cnt3;j++){
					int nc=a[i].z-a[th[j]].z+max(a[th[j]].x,a[th[j]].y);
					if(nc>c){
						p=j;
						c=nc;
					}
				}
				int xc=max(a[i].y,a[i].x);
				if(xc>c) p=-1;
				if(p>-1){
					int x=a[th[p]].x,y=a[th[p]].y;
					if(x>y){
						on[++cnt1]=th[p];
					}else{
						tw[++cnt2]=th[p];
					}
					th[p]=i;
				}else{
					int x=a[i].x,y=a[i].y;
					if(x>y){
						on[++cnt1]=i;
					}else{
						tw[++cnt2]=i;
					}
				} 
			}
		} 
	}
	int cnt=0;
	for(int i=1;i<=cnt1;i++) cnt+=a[on[i]].x;
	for(int i=1;i<=cnt2;i++) cnt+=a[tw[i]].y;
	for(int i=1;i<=cnt3;i++) cnt+=a[th[i]].z;
	cout<<cnt<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int k;
	cin>>k;
	while(k--){
		l();
	} 
	return 0;
} 
