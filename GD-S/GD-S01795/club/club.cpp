#include<bits/stdc++.h>
using namespace std;
long long t,n,sl[15];
struct node{
	long long x,y,z;
}a[100005];
bool cmp(node xx,node yy){
	int xx_max=max(xx.x,max(xx.y,xx.z));
	int xx_min=min(xx.x,min(xx.y,xx.z));
	int xx_mid=xx.x+xx.y+xx.z-xx_max-xx_min;	
	int yy_max=max(yy.x,max(yy.y,yy.z));
	int yy_min=min(yy.x,min(yy.y,yy.z));
	int yy_mid=yy.x+yy.y+yy.z-yy_max-yy_min;
//	if(abs(xx.x-xx.y)+abs(xx.y-xx.z)+abs(xx.x-xx.z)!=abs(yy.x-yy.y)+abs(yy.y-yy.z)+abs(yy.x-yy.z))return abs(xx.x-xx.y)+abs(xx.y-xx.z)+abs(xx.x-xx.z)>abs(yy.x-yy.y)+abs(yy.y-yy.z)+abs(yy.x-yy.z);
	return xx_max-xx_mid>yy_max-yy_mid; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long ans=0;
		sl[1]=sl[2]=sl[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			int ma=max(a[i].x,max(a[i].y,a[i].z));
			int mi=min(a[i].x,min(a[i].y,a[i].z));
			int mid=a[i].x+a[i].y+a[i].z-ma-mi;
			int mawz,miwz,midwz;
			if(ma==a[i].x)mawz=1;
			if(ma==a[i].y)mawz=2;
			if(ma==a[i].z)mawz=3;
			if(mi==a[i].x)miwz=1;
			if(mi==a[i].y)miwz=2;
			if(mi==a[i].z)miwz=3;
			if(mid==a[i].x)midwz=1;
			if(mid==a[i].y)midwz=2;
			if(mid==a[i].z)midwz=3;
			if(sl[mawz]<n/2){
				ans+=ma;
				sl[mawz]++; 
			}
			else if(sl[midwz]<n/2){
				ans+=mid;
				sl[midwz]++;
			} 
			else{
				ans+=mi;
				sl[miwz]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
