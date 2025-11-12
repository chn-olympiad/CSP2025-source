#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int x,y,z,ma,xx;
};
bool cmpx(node a,node b){
	return a.x>b.x;
}
bool cmpy(node a,node b){
	return a.y>b.y;
}
bool cmpz(node a,node b){
	return a.z>b.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long ans=0;
		node a[100005];
		bool w=true,m=true;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].xx=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].y!=0) w=false;
			if(a[i].z!=0) m=false;
 			if(a[i].xx==a[i].x) a[i].ma=1;
			else if(a[i].xx==a[i].y) a[i].ma=2;
			else a[i].ma=3;
		}
		if(n==2){
			if(a[1].ma==a[2].ma){
				if(a[1].ma==1) ans=max(a[1].x+max(a[2].y,a[2].z),a[2].x+max(a[1].y,a[1].z));
				else if(a[1].ma==2) ans=max(a[1].y+max(a[2].x,a[2].z),a[2].y+max(a[1].x,a[1].z));
				else ans=max(a[1].z+max(a[2].y,a[2].x),a[2].z+max(a[1].y,a[1].x));
			}
			else ans=a[1].xx+a[2].xx;
		}
		else if(w==true&&m==true){
			sort(a+1,a+1+n,cmpx);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
		}
		else if(w!=true&&m==true){
			sort(a+1,a+1+n,cmpx);
			for(int i=1;i<=n/2;i++){
				if(a[i].ma==1){
					ans+=a[i].x;
				}
			}
			sort(a+1,a+1+n,cmpy);
			for(int i=1;i<=n/2;i++){
				if(a[i].ma==2){
					ans+=a[i].y;
				}
			}
		}
		else{
			sort(a+1,a+1+n,cmpx);
			for(int i=1;i<=n/2;i++) if(a[i].ma==1) ans+=a[i].x;
			sort(a+1,a+1+n,cmpy);
			for(int i=1;i<=n/2;i++) if(a[i].ma==2) ans+=a[i].y;
			sort(a+1,a+1+n,cmpz);
			for(int i=1;i<=n/2;i++) if(a[i].ma==3) ans+=a[i].z;	
		}
		cout<<ans<<endl;
	}
	return 0;
} 
