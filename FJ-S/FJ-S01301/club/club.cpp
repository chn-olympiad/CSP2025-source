#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct node{
	int x,y,z;
}a[N],b[N],c[N],d[N];
int cntx[N],cnty[N],cntz[N];
bool cmp(node a,node b){
	return max(max(a.x,a.y),a.z)>=max(max(b.x,b.y),b.z);
}
bool cmp1(node a,node b){
	return min(a.x-a.y,a.x-a.z)<=min(b.x-b.y,b.x-b.z);
}
bool cmp2(node a,node b){
	return min(a.y-a.x,a.y-a.z)<=min(b.y-b.x,b.y-b.z);
}
bool cmp3(node a,node b){
	return min(a.z-a.x,a.z-a.y)<=min(b.z-b.x,b.z-b.y);
}
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+n+1,cmp);
		long long ans=0;
		int cx=0,cy=0,cz=0;
		for(int i=1;i<=n;i++){
			int k=max(max(a[i].x,a[i].y),a[i].z);
			ans+=k;
			if(k==a[i].x){
				b[++cx].x=a[i].x;
				b[cx].y=a[i].y;
				b[cx].z=a[i].z;
			}
			else if(k==a[i].y){
				c[++cy].x=a[i].x;
				c[cy].y=a[i].y;
				c[cy].z=a[i].z;
			}
			else{
				d[++cz].x=a[i].x;
				d[cz].y=a[i].y;
				d[cz].z=a[i].z;
			}
		}
		if(cx>n/2){
			sort(b+1,b+cx+1,cmp1);
			for(int i=1;i<=cx-n/2;i++)ans-=min(b[i].x-b[i].y,b[i].x-b[i].z);
		}
		if(cy>n/2){
			sort(c+1,c+cy+1,cmp2);
			for(int i=1;i<=cy-n/2;i++)ans-=min(c[i].y-c[i].x,c[i].y-c[i].z);
		}
		if(cz>n/2){
			sort(d+1,d+cz+1,cmp3);
			for(int i=1;i<=cz-n/2;i++)ans-=min(d[i].z-d[i].x,d[i].z-d[i].y);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

