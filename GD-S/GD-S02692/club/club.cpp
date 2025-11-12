#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t;
int n,ans;
int cura,curb,curc;
struct node{
	int x,y,z;
	void read(){
		cin>>x>>y>>z;
	}
}a[maxn];
node cnta[maxn],cntb[maxn],cntc[maxn];
bool cmpa(node i,node j){
	return i.x<j.x;
}
bool cmpb(node i,node j){
	return i.y<j.y;
}
bool cmpc(node i,node j){
	return i.z<j.z;
}
void init(){
	memset(cnta,0,sizeof(cnta));
	memset(cntb,0,sizeof(cntb));
	memset(cntc,0,sizeof(cntc));
	memset(a,0,sizeof(a));
	cura=curb=curc=ans=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		init();
		cin>>n;
		for (int i=1;i<=n;i++) a[i].read();
		for (int i=1;i<=n;i++){
			if (max({a[i].x,a[i].y,a[i].z})==a[i].x){
//				cout<<"a:"<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<" "<<cura<<endl;
				node p={-1,-1,-1};
				int l;
				if (cura<n/2) cnta[++cura]=a[i];
				else{
					for (int j=1;j<=cura;j++){
						if (a[i].x+cnta[j].y>cnta[j].x+a[i].y){
							if (p.x==-1 && p.y==-1 && p.z==-1 || p.x==a[i].x && p.y==a[i].y && p.z==a[i].z) p=cnta[j],cnta[j]=a[i],l=j;
							else if (a[i].x+cntc[j].y-cntc[j].x-a[i].y>a[i].x+cntc[l].y-cntc[l].x-a[i].y) cnta[l]=p,p=cnta[j],cnta[j]=a[i],l=j;
//							break;
						}
						else if (a[i].x+cnta[j].z>cnta[j].x+a[i].z){
							if (p.x==-1 && p.y==-1 && p.z==-1 || p.x==a[i].x && p.y==a[i].y && p.z==a[i].z) p=cnta[j],cnta[j]=a[i],l=j;
							else if (a[i].x+cntc[j].z-cntc[j].x-a[i].z>a[i].x+cntc[l].z-cntc[l].x-a[i].z) cnta[l]=p,p=cnta[j],cnta[j]=a[i],l=j;
//							break;
						}
						else if (p.x==-1 && p.y==-1 && p.z==-1) p=a[i];
					}
					if (max(p.y,p.z)==p.y) cntb[++curb]=p;
					if (max(p.y,p.z)==p.z) cntc[++curc]=p;
				}
				sort(cnta+1,cnta+cura+1,cmpa);
			}
			if (max({a[i].x,a[i].y,a[i].z})==a[i].y){
//				cout<<"b:"<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<" "<<curb<<endl;
				node p={-1,-1,-1};
				int l;
				if (curb<n/2) cntb[++curb]=a[i];
				else{
					for (int j=1;j<=curb;j++){
						if (a[i].y+cntb[j].x>cntb[j].y+a[i].x){
							if (p.x==-1 && p.y==-1 && p.z==-1 || p.x==a[i].x && p.y==a[i].y && p.z==a[i].z) p=cntb[j],cntb[j]=a[i],l=j;
							else if (a[i].y+cntc[j].x-cntc[j].y-a[i].x>a[i].y+cntc[l].x-cntc[l].y-a[i].x) cntb[l]=p,p=cntb[j],cntb[j]=a[i],l=j;
//							break;
						}
						else if (a[i].y+cnta[j].z>cnta[j].y+a[i].z){
							if (p.x==-1 && p.y==-1 && p.z==-1 || p.x==a[i].x && p.y==a[i].y && p.z==a[i].z) p=cntb[j],cntb[j]=a[i],l=j;
							else if (a[i].y+cntc[j].z-cntc[j].y-a[i].z>a[i].y+cntc[l].z-cntc[l].y-a[i].z) cntb[l]=p,p=cntb[j],cntb[j]=a[i],l=j;
//							break;
						}
						else if (p.x==-1 && p.y==-1 && p.z==-1) p=a[i];
					}
					if (max(p.x,p.z)==p.x) cnta[++cura]=p;
					if (max(p.x,p.z)==p.z) cntc[++curc]=p;
				}
				sort(cntb+1,cntb+curb+1,cmpb);
			}
			if (max({a[i].x,a[i].y,a[i].z})==a[i].z){
//				cout<<"c:"<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<" "<<curc<<endl;
				node p={-1,-1,-1};
				int l;
				if (curc<n/2) cntc[++curc]=a[i];
				else{
					for (int j=1;j<=curc;j++){
						if (a[i].z+cntc[j].x>cntc[j].z+a[i].x){
							if (p.x==-1 && p.y==-1 && p.z==-1 || p.x==a[i].x && p.y==a[i].y && p.z==a[i].z) p=cntc[j],cntc[j]=a[i],l=j;
							else if (a[i].z+cntc[j].x-cntc[j].z-a[i].x>a[i].z+cntc[l].x-cntc[l].z-a[i].x) cntc[l]=p,p=cntc[j],cntc[j]=a[i],l=j;
//							break;
						}
						else if (a[i].z+cntc[j].y>cntc[j].z+a[i].y){
							if (p.x==-1 && p.y==-1 && p.z==-1 || p.x==a[i].x && p.y==a[i].y && p.z==a[i].z) p=cntc[j],cntc[j]=a[i],l=j;
							else if (a[i].z+cntc[j].y-cntc[j].z-a[i].y>a[i].z+cntc[l].y-cntc[l].z-a[i].y) cntc[l]=p,p=cntc[j],cntc[j]=a[i],l=j;
//							break;
						}
						else if (p.x==-1 && p.y==-1 && p.z==-1) p=a[i];
					}
					if (max(p.x,p.y)==p.x) cnta[++cura]=p;
					if (max(p.x,p.y)==p.y) cntb[++curb]=p;
				}
				sort(cntc+1,cntc+curc+1,cmpc);
			}
		}
//		cout<<cura+curb+curc<<endl;
//		cout<<cura<<" "<<curb<<" "<<curc<<endl;
//		cout<<"a:"<<endl;
//		for (int i=1;i<=cura;i++) cout<<cnta[i].x<<" "<<cnta[i].y<<" "<<cnta[i].z<<endl;
//		cout<<endl<<"b:"<<endl;
//		for (int i=1;i<=curb;i++) cout<<cntb[i].x<<" "<<cntb[i].y<<" "<<cntb[i].z<<endl;
//		cout<<endl<<"c:"<<endl;
//		for (int i=1;i<=curc;i++) cout<<cntc[i].x<<" "<<cntc[i].y<<" "<<cntc[i].z<<endl;
//		cout<<endl;
		for (int i=1;i<=cura;i++) ans+=cnta[i].x;
		for (int i=1;i<=curb;i++) ans+=cntb[i].y;
		for (int i=1;i<=curc;i++) ans+=cntc[i].z;
		cout<<ans<<endl;
	}
	return 0;
}
