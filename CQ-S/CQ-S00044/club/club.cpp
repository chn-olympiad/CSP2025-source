#include<bits/stdc++.h>
using namespace std;
int T;
struct node{
	int x,y,z,t;
}a[100005];
bool vis[5];
int sum[5];
int n;
int ans=0;
int sss;
void dfs(int x){
	for(int i=x+1;i<=n;i++){
		if(!vis[1]){
			sum[1]++;
			if(sum[1]>=n/2){
				vis[1]=true;
			}
			sss+=a[i].x;
			dfs(i);
			sss-=a[i].x;
			sum[1]--;
			if(sum[1]<n/2){
				vis[1]=false;
			}
		}
		if(!vis[2]){
			sum[2]++;
			if(sum[2]>=n/2){
				vis[2]=true;
			}
			sss+=a[i].y;
			dfs(i);
			sss-=a[i].y;
			sum[2]--;
			if(sum[2]<n/2){
				vis[2]=false;
			}
		}
		if(!vis[3]){
			sum[3]++;
			if(sum[3]>=n/2){
				vis[3]=true;
			}
			sss+=a[i].z;
			dfs(i);
			sss-=a[i].z;
			sum[3]--;
			if(sum[3]<n/2){
				vis[3]=false;
			}
		}
		if(vis[1]&&vis[2]&&vis[3])break;
	}
	ans=max(ans,sss);
}
void solve(){
	cin>>T;
	while(T--){
		cin>>n;
		sss=0;
		ans=0;
		memset(sum,0,sizeof sum);
		memset(vis,false,sizeof vis);
		bool all1=true,all2=true;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x!=0||a[i].z!=0){
				all1=false;
			}
			if(a[i].z!=0)all2=false;
		}
		if(n<=10){
			dfs(0);
			cout<<ans<<endl;
		}else{
			int k=n/2;
		if(all1){
			int ans=0;
			int t[20005];
			for(int i=1;i<=n;i++){
				t[a[i].x]++;
			}
			
			for(int i=0;i<=20000;i++){
				if(t[i]){
					if(k>=t[i]){
						k-=t[i];
					}else{
						t[i]-=k;
						k=0;
						ans+=t[i]*i;
					}
				}
			}
			cout<<ans;
		}else{
			for(int i=1;i<=n;i++){
				a[i].t=min({a[i].x,a[i].y,a[i].z});
				a[i].x-=a[i].t,a[i].y-=a[i].t,a[i].z-=a[i].t;
			}
			for(int i=1;i<=n;i++){
				int maxn=a[i].x,id=1;
				if(a[i].y>maxn){
					id=2;
					maxn=a[i].y;
				}
				if(a[i].z>maxn){
					id=3;
					maxn=a[i].z;
				}
				if(sum[id]<k){
					ans+=maxn+a[i].t;
					sum[id]++;
				}else{
					if(id==1){
						ans+=max(a[i].y,a[i].z)+a[i].t;
						if(a[i].y>a[i].z){
							sum[2]++;
						}else sum[3]++;
					}
					if(id==2){
						ans+=max(a[i].x,a[i].z)+a[i].t;
						if(a[i].x>a[i].z){
							sum[1]++;
						}else sum[3]++;
					}
					if(id==3){
						ans+=max(a[i].y,a[i].x)+a[i].t;
						if(a[i].y>a[i].x){
							sum[2]++;
						}else sum[1]++;
					}
				}
			}
			cout<<ans<<endl;
		}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	solve();
	return 0;
}

