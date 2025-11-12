#include<bits/stdc++.h>
using namespace std;
#define int long long
int tt;
int n;
struct edge{
	int x,y,z;
}a[100005];
int h,z,y;
int s[100005];
int p[100005];
bool cmp(int xx,int yy){
	return xx>yy;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>tt;
	while(tt--){
		int cnt=0,ans=0;
		h=0,y=0,z=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if((a[i].x>=a[i].y)&&(a[i].x>=a[i].z)){
				h++;
				s[i]=1;
				ans+=a[i].x;
			}
			else if((a[i].y>=a[i].x)&&(a[i].y>=a[i].z)){
				z++;
				s[i]=2;
				ans+=a[i].y;
			}	
			else{
				y++;
				s[i]=3;
				ans+=a[i].z;
			}				
		}
		if(h>n/2){
			for(int i=1;i<=n;i++){
				if(s[i]==1){
					p[++cnt]=max(a[i].y,a[i].z)-a[i].x;
				}
			}
			sort(p+1,p+cnt+1,cmp);
			for(int i=1;i<=h-n/2;i++){
				ans+=p[i];
			}
		}
		if(z>n/2){
			for(int i=1;i<=n;i++){
				if(s[i]==2){
					p[++cnt]=max(a[i].x,a[i].z)-a[i].y;
				}
			}
			sort(p+1,p+cnt+1,cmp);
			for(int i=1;i<=z-n/2;i++){
				ans+=p[i];
			}				
		}
		if(y>n/2){
			for(int i=1;i<=n;i++){
				if(s[i]==3){
					p[++cnt]=max(a[i].x,a[i].y)-a[i].z;
				}
			}
			sort(p+1,p+cnt+1,cmp);
			for(int i=1;i<=y-n/2;i++){
				ans+=p[i];
			}				
		}	
		cout<<ans<<endl;
	}
	return 0;
} 
