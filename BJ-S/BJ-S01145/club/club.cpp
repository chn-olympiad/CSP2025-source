#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
struct node{
	int f,s,l,ch;
}g[1000005];
int vis[5];
void check(int i,int x,int y,int z){
	if(x>=y&&y>=z){
		g[i].f=1,g[i].s=2,g[i].l=3;
		g[i].ch=a[i][g[i].f]-a[i][g[i].s];
	}else if(x>=z&&z>=y){
		g[i].f=1,g[i].s=3,g[i].l=2;
		g[i].ch=a[i][g[i].f]-a[i][g[i].s];
	}else if(y>=x&&x>=z){
		g[i].f=2,g[i].s=1,g[i].l=3;
		g[i].ch=a[i][g[i].f]-a[i][g[i].s];
	}else if(y>=z&&z>=x){
		g[i].f=2,g[i].s=3,g[i].l=1;
		g[i].ch=a[i][g[i].f]-a[i][g[i].s];
	}else if(z>=x&&x>=y){
		g[i].f=3,g[i].s=1,g[i].l=2;
		g[i].ch=a[i][g[i].f]-a[i][g[i].s];
	}else if(z>=y&&y>=x){
		g[i].f=3,g[i].s=2,g[i].l=1;
		g[i].ch=a[i][g[i].f]-a[i][g[i].s];
	}
}
int cmp(node x,node y){
	return x.ch<y.ch;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		int n;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			check(i,a[i][1],a[i][2],a[i][3]);
			ans+=a[i][g[i].f];
			vis[g[i].f]++;
		}
		if(max(vis[1],max(vis[2],vis[3]))<=n/2){
			cout<<ans<<endl;
			continue;
		}
		int k;
		k=max(vis[1],max(vis[2],vis[3]));
		if(k==vis[1]){
			sort(g+1,g+n+1,cmp);
			int idx=1;
			while(vis[1]>n/2){
				if(g[idx].f==1){
					ans-=g[idx].ch;
					vis[1]--;
				}
				idx++;
			}
		}else if(k==vis[2]){
			sort(g+1,g+n+1,cmp);
			int idx=1;
			while(vis[2]>n/2){
				if(g[idx].f==2){
					ans-=g[idx].ch;
					vis[2]--;
				}
				idx++;
			}
		}else{
			sort(g+1,g+n+1,cmp);
			int idx=1;
			while(vis[3]>n/2){
				if(g[idx].f==3){
					ans-=g[idx].ch;
					vis[3]--;
				}
				idx++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
