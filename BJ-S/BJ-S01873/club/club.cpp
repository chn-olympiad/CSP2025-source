#include<bits/stdc++.h>
using namespace std;
int a[100100][10],n,t,vis[10];
long long ans;
struct node{
	long long v;
	int id;
}s[100100];
bool cmp(node x,node y){
	return x.v>=y.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long ans=0;
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			s[i].v=max(a[i][1],max(a[i][2],a[i][3]));
			s[i].id=i;
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			int x=a[s[i].id][1],y=a[s[i].id][2],z=a[s[i].id][3];
			if(x>y&&x>z){
				if(vis[1]<n/2){
					ans+=x;
					vis[1]++;
				}
				else{
					if(y>z&&vis[2]<n/2) ans+=y,vis[2]++;
					if(y<z&&vis[3]<n/2) ans+=z,vis[3]++;
					if(y==z&&vis[2]<vis[3]) ans+=y,vis[2]++;
					if(y==z&&vis[2]>vis[3]) ans+=z,vis[3]++;
				}
			}
			if(x<y&&y>z){
				if(vis[2]<n/2){
					ans+=y;
					vis[2]++;
				}
				else{
					if(x>z&&vis[1]<n/2) ans+=x,vis[1]++;
					if(x<z&&vis[3]<n/2) ans+=z,vis[3]++;
					if(x==z&&vis[1]<vis[3]) ans+=x,vis[1]++;
					if(x==z&&vis[1]>vis[3]) ans+=z,vis[3]++;
				}
			}
			if(z>y&&x<z){
				if(vis[3]<n/2){
					ans+=z;
					vis[3]++;
				}
				else{
					if(y>x&&vis[2]<n/2) ans+=y,vis[2]++;
					if(y<x&&vis[1]<n/2) ans+=x,vis[1]++;
					if(y==x&&vis[2]<vis[1]) ans+=y,vis[2]++;
					if(y==x&&vis[2]>vis[1]) ans+=x,vis[1]++;
				}
			}
			if(x==y&&x>z){
				if(vis[1]<=vis[2]) ans+=x,vis[1]++;
				if(vis[1]>vis[2]) ans+=y,vis[2]++;
			}
			if(z==y&&x<z){
				if(vis[3]<=vis[2]) ans+=z,vis[3]++;
				if(vis[3]>vis[2]) ans+=y,vis[2]++;
			}
			if(x==z&&x>y){
				if(vis[1]<=vis[3]) ans+=x,vis[1]++;
				if(vis[1]>vis[3]) ans+=z,vis[3]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
