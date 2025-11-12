#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n,m;
struct node{
	int x,y,z,mx;
}e[N],p[N];
bool cmp1(node a,node b){
	if((a.y+b.x>a.x+b.y)||(a.z+b.x>a.x+b.z)){
		return true;
	}
	return false;
}
bool cmp2(node a,node b){
	if((a.x+b.y>a.y+b.x)||(a.z+b.y>a.y+b.z)){
		return true;
	}
	return false;
}
bool cmp3(node a,node b){
	if((a.y+b.z>a.z+b.y)||(a.y+b.z>a.z+b.y)){
		return true;
	}
	return false;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		int yi=0,er=0,san=0;
		memset(e,0,sizeof(e));
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			cin>>e[i].x>>e[i].y>>e[i].z;
			if(e[i].x>=e[i].y&&e[i].x>=e[i].z){
				e[i].mx=1;
				yi++;
			}else if(e[i].y>=e[i].x&&e[i].y>=e[i].z){
				e[i].mx=2;
				er++;
			}else{
				e[i].mx=3;
				san++;
			}
		}
		int tot=0;
		int ans=0;
		if(yi>(n/2)){
			for(int i=1;i<=n;i++){
				if(e[i].mx==1){
					p[++tot].x=e[i].x;
					p[tot].y=e[i].y;
					p[tot].z=e[i].z;
					p[tot].mx=1;
				}else if(e[i].mx==2){
					ans+=e[i].y;
				}else{
					ans+=e[i].z;
				}
			}
			sort(p+1,p+tot+1,cmp1);
			for(int i=(n/2)+1;i<=n;i++){
				for(int j=1;j<=n/2;j++){
					if(p[j].y+p[i].x>p[j].x+p[i].y){
						if(p[j].z>p[j].y){
							p[j].mx=3;
						}else{
							p[j].mx=2;
						}
						break;
					}
				}
			}
			for(int i=1;i<=tot;i++){
				if(p[i].mx==1){
					ans+=p[i].x;
				}else if(p[i].mx==2){
					ans+=p[i].y;
				}else{
					ans+=p[i].z;
				}
			}
		}else if(er>(n/2)){
			for(int i=1;i<=n;i++){
				if(e[i].mx==2){
					p[++tot].x=e[i].x;
					p[tot].y=e[i].y;
					p[tot].z=e[i].z;
					p[tot].mx=2;
				}else if(e[i].mx==1){
					ans+=e[i].x;
				}else{
					ans+=e[i].z;
				}
			}
			sort(p+1,p+tot+1,cmp2);
			for(int i=(n/2)+1;i<=n;i++){
				for(int j=1;j<=n/2;j++){
					if(p[j].x+p[i].y>p[j].y+p[i].x){
						if(p[j].z>p[j].x){
							p[j].mx=3;
						}else{
							p[j].mx=1;
						}
						break;
					}
				}
			}
			for(int i=1;i<=tot;i++){
				if(p[i].mx==1){
					ans+=p[i].x;
				}else if(p[i].mx==2){
					ans+=p[i].y;
				}else{
					ans+=p[i].z;
				}
			}
		}else if(san>(n/2)){
			for(int i=1;i<=n;i++){
				if(e[i].mx==3){
					p[++tot].x=e[i].x;
					p[tot].y=e[i].y;
					p[tot].z=e[i].z;
					p[tot].mx=3;
				}else if(e[i].mx==1){
					ans+=e[i].x;
				}else{
					ans+=e[i].y;
				}
			}
			sort(p+1,p+tot+1,cmp3);
			for(int i=(n/2)+1;i<=n;i++){
				for(int j=1;j<=n/2;j++){
					if(p[j].x+p[i].z>p[j].z+p[i].x){
						if(p[j].y>p[j].x){
							p[j].mx=2;
						}else{
							p[j].mx=1;
						}
						break;
					}
				}
			}
			for(int i=1;i<=tot;i++){
				if(p[i].mx==1){
					ans+=p[i].x;
				}else if(p[i].mx==2){
					ans+=p[i].y;
				}else{
					ans+=p[i].z;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(e[i].mx==1){
					ans+=e[i].x;
				}else if(e[i].mx==2){
					ans+=e[i].y;
				}else{
					ans+=e[i].z;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
