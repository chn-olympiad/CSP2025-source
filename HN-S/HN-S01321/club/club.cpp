#include<bits/stdc++.h>
using namespace std;
struct x{
	int x,y,z;
	bool g;
}c[500010];
bool cmp1(x a,x b){
	return a.x>b.x;
}
bool cmp2(x a,x b){
	return a.y>b.y;
}
bool cmp3(x a,x b){
	return a.z>b.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n,ans=0;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>c[i].x>>c[i].y>>c[i].z;
			c[i].g=true;
		}
		sort(c+1,c+1+n,cmp1);
		for(int i=1;i<=n/2;i++){
			int mx=max(c[i].x,max(c[i].y,c[i].z));
			int cl=(mx==c[i].x)?1:(mx==c[i].y)?2:3;
			if(cl==1&&c[i].g){
				ans+=mx;
				c[i].g=false;
			}
		}
		sort(c+1,c+1+n,cmp2);
		for(int i=1;i<=n/2;i++){
			int mx=max(c[i].x,max(c[i].y,c[i].z));
			int cl=(mx==c[i].x)?1:(mx==c[i].y)?2:3;
			if(cl==2&&c[i].g){
				ans+=mx;
				c[i].g=false;
			}
		}
		sort(c+1,c+1+n,cmp3);
		for(int i=1;i<=n/2;i++){
			int mx=max(c[i].x,max(c[i].y,c[i].z));
			int cl=(mx==c[i].x)?1:(mx==c[i].y)?2:3;
			if(cl==3&&c[i].g){
				ans+=mx;
				c[i].g=false;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
