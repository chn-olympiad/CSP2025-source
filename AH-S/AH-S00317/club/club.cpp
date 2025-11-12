#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int x,y,z;
}a[100005];
int vis[4];
long long ans;
int cha[300005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		vis[1]=0;vis[2]=0;vis[3]=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				vis[1]++;
			}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				vis[2]++;
			}else vis[3]++;
			ans+=max(max(a[i].x,a[i].y),a[i].z);
		}
	//	cout<<ans<<endl;
		if(vis[1]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
					cha[++cnt]=a[i].x-max(a[i].y,a[i].z);
				}
			}
			sort(cha+1,cha+1+cnt);
			int g=1;
			while(vis[1]>n/2){
				ans-=cha[g++];
				vis[1]--;
			}
		}else if(vis[2]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
					cha[++cnt]=a[i].y-max(a[i].x,a[i].z);
				}
			}
			sort(cha+1,cha+1+cnt);
			int g=1;
			while(vis[2]>n/2){
				ans-=cha[g++];
				vis[2]--;
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i].z>=a[i].y&&a[i].z>=a[i].x){
					cha[++cnt]=a[i].z-max(a[i].y,a[i].x);
				}
			}
			sort(cha+1,cha+1+cnt);
			int g=1;
			while(vis[3]>n/2){
				ans-=cha[g++];
				vis[3]--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
