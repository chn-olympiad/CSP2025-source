#include<bits/stdc++.h>
using namespace std;
struct sx{
	int x,y,z,s;
}yg[100005];
bool cmp(sx a,sx b){
	int x=max(a.x,max(a.y,a.z)),y=max(b.x,max(b.y,b.z));
	int z=min(a.x,min(a.y,a.z)),s=min(b.x,min(b.y,b.z));
	if(x==y){
		if(x-z==y-s){
			return z>s;
		}else{
			return x-z>y-s;
		}
	}else{
		return x>y;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,a=0,b=0,c=0,x,y,z,ans=0;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>yg[i].x>>yg[i].y>>yg[i].z;
			if(yg[i].x>=yg[i].y&&yg[i].x>=yg[i].z){
				yg[i].s=1;
			}else if(yg[i].y>=yg[i].x&&yg[i].y>=yg[i].z){
				yg[i].s=2;
			}else{
				yg[i].s=3;
			}
		}
		sort(yg+1,yg+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(yg[i].s==1){
				if(a>=n/2){
					if(yg[i].x+max(y,z)>x+max(yg[i].y,yg[i].z)){
						ans+=yg[i].x-x+max(y,z);
						if(max(y,z)==y) b++;
						else c++;
					}else{
						ans+=max(yg[i].y,yg[i].z);
					}
				}else{
					a++;
					ans+=yg[i].x;
				}
			} 
			if(yg[i].s==2){
				if(b>=n/2){
					if(yg[i].y+max(x,z)>y+max(yg[i].x,yg[i].z)){
						ans+=yg[i].x-y+max(x,z);
						if(max(x,z)==y) a++;
						else c++;
					}else{
						ans+=max(yg[i].z,yg[i].x);
					}
				}else{
					b++;
					ans+=yg[i].y;
				}
			} 
			if(yg[i].s==3){
				if(c>=n/2){
					if(yg[i].z+max(y,x)>z+max(yg[i].y,yg[i].x)){
						ans+=yg[i].z-x+max(y,x);
						if(max(y,x)==x) a++;
						else b++;
					}else{
						ans+=max(yg[i].y,yg[i].x);
					}
				}else{
					c++;
					ans+=yg[i].z;
				}
			}
			if(a==n/2||b==n/2||c==n/2){
				x=yg[i].x;
				y=yg[i].y;
				z=yg[i].z;
			}
		}
		a=0;
		b=0;
		c=0;
		cout<<ans<<endl;
		ans=0;
	}
	
	return 0;
}
