#include<bits/stdc++.h>
using namespace std;
int T,n,m,x,xx,y,yy,z,zz,t,ans,cnt;
struct node{int x,y,z;}a[1000015];
struct node1{int x,y;}b[1000015];
bool cmp(node x,node y){
	return x.x<y.x;
}
bool cmpp(node x,node y){
	return x.x>y.x;
}
bool cmp1(node1 x,node1 y){
	return x.x>y.x;
}
bool cmp2(node1 x,node1 y){
	return x.x<y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+1+n,cmp);
		for(int i=1,x=0;i<=n;i++){
			if(a[i].y>a[i].x||a[i].z>a[i].x||x==n/2)b[++t].x=a[i].y,b[t].y=a[i].z;
			else ans+=a[i].x,x++;
		}
		sort(b+1,b+1+t,cmp1);
		for(int i=1,x=0,y=0;i<=t;i++){
			if((b[i].y>b[i].x||x==n/2)&&y!=n/2)ans+=b[i].y,y++;
			else ans+=b[i].x,x++; 
		}
		cnt=max(cnt,ans),ans=0,t=0;
		sort(a+1,a+1+n,cmpp);
		for(int i=1,x=0;i<=n;i++){
			if(a[i].y>a[i].x||a[i].z>a[i].x||x==n/2)b[++t].x=a[i].y,b[t].y=a[i].z;
			else ans+=a[i].x,x++;
		}
		sort(b+1,b+1+t,cmp1);
		for(int i=1,x=0,y=0;i<=t;i++){
			if((b[i].y>b[i].x||x==n/2)&&y!=n/2)ans+=b[i].y,y++;
			else ans+=b[i].x,x++; 
		}
		cnt=max(cnt,ans),ans=0,t=0;
		sort(a+1,a+1+n,cmpp);
		for(int i=1,x=0;i<=n;i++){
			if(a[i].y>a[i].x||a[i].z>a[i].x||x==n/2)b[++t].x=a[i].y,b[t].y=a[i].z;
			else ans+=a[i].x,x++;
		}
		sort(b+1,b+1+t,cmp2);
		for(int i=1,x=0,y=0;i<=t;i++){
			if((b[i].y>b[i].x||x==n/2)&&y!=n/2)ans+=b[i].y,y++;
			else ans+=b[i].x,x++; 
		}
		cnt=max(cnt,ans),ans=0,t=0;
		sort(a+1,a+1+n,cmp);
		for(int i=1,x=0;i<=n;i++){
			if(a[i].y>a[i].x||a[i].z>a[i].x||x==n/2)b[++t].x=a[i].y,b[t].y=a[i].z;
			else ans+=a[i].x,x++;
		}
		sort(b+1,b+1+t,cmp2);
		for(int i=1,x=0,y=0;i<=t;i++){
			if((b[i].y>b[i].x||x==n/2)&&y!=n/2)ans+=b[i].y,y++;
			else ans+=b[i].x,x++; 
		}
		cout<<max(cnt,ans)<<endl,ans=0,t=0,cnt=0;
	}
	
	
	return 0;
} 
