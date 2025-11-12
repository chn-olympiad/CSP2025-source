#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,z,no;
}a[100005],b[100005],c[100005];
bool vis[100005];
bool cmpa(node first,node second){
	return first.x>second.x;
}
bool cmpb(node first,node second){
	return first.y>second.y;
}
bool cmpc(node first,node second){
	return first.z>second.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	long long t;
	cin>>t;
	while(t--){
		//记得初始化
		memset(vis,0,sizeof(vis));
		long long n,ans=0;
		//输入
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].no=i;
			b[i].x=a[i].x;
			b[i].y=a[i].y;
			b[i].z=a[i].z;
			b[i].no=i;
			c[i].x=a[i].x;
			c[i].y=a[i].y;
			c[i].z=a[i].z;
			c[i].no=i;
		}
		//排序
		sort(a+1,a+n+1,cmpa);
		sort(b+1,b+n+1,cmpb);
		sort(c+1,c+n+1,cmpc);
		long long ya=0,yb=0,yc=0;
		for(int i=1,aa=1,bb=1,cc=1;i<=n;i++){
			//找到每组的目前第一个没访问过的点
			while(vis[a[aa].no]){
				aa++;
			}
			while(vis[b[bb].no]){
				bb++;
			}
			while(vis[c[cc].no]){
				cc++;
			}
			//找每组当前最大值
			if(max(a[aa].x,max(b[bb].y,c[cc].z))==a[aa].x&&ya<n/2){
				if(ya+1==n/2){
					int k;
					for(k=1;vis[a[aa+k].no];k++);
					if(max(a[aa].y,a[aa].z)==a[aa].y){
						if(a[aa].x<a[aa].y+a[aa+k].x&&yb<n/2){
							vis[a[aa].no]=1;
							ans+=a[aa].y;
							continue;
						}
					}
					else{
						if(a[aa].x<a[aa].y+a[aa+k].x&&yc<n/2){
							vis[a[aa].no]=1;
							ans+=a[aa].z;
							continue;
						}
					}
				}
				vis[a[aa].no]=1;
				ans+=a[aa].x;
				aa++;
				ya++;
			}
			else if(max(a[aa].x,max(b[bb].y,c[cc].z))==b[bb].y&&yb<n/2){
				if(yb+1==n/2){
					int k;
					for(k=1;vis[b[bb+k].no];k++);
					if(max(b[bb].x,b[bb].z)==b[bb].x){
						if(b[bb].y<b[bb].x+b[bb+k].y&&ya<n/2){
							vis[b[bb].no]=1;
							ans+=b[bb].x;
							continue;
						}
					}
					else{
						if(b[bb].y<b[bb].z+b[bb+k].y&&yc<n/2){
							vis[b[bb].no]=1;
							ans+=b[bb].z;
							continue;
						}
					}
				}
				vis[b[bb].no]=1;
				ans+=b[bb].y;
				bb++;
				yb++;
			}
			else if(max(a[aa].x,max(b[bb].y,c[cc].z))==c[cc].z&&yc<n/2){
				if(yc+1==n/2){
					int k;
					for(k=1;vis[c[cc+k].no];k++);
					if(max(c[cc].x,c[cc].y)==c[cc].x){
						if(c[cc].z<c[cc].x+c[cc+k].z&&ya<n/2){
							vis[c[cc].no]=1;
							ans+=c[cc].x;
							continue;
						}
					}
					else{
						if(c[cc].z<c[cc].y+c[cc+k].z&&yb<n/2){
							vis[c[cc].no]=1;
							ans+=c[cc].y;
							continue;
						}
					}
				}
				vis[c[cc].no]=1;
				ans+=c[cc].z;
				cc++;
				yc++;
			}
			//最大没有找次大
			else if(max(a[aa].x,max(b[bb].y,c[cc].z))!=a[aa].x&&min(a[aa].x,min(b[bb].y,c[cc].z))!=a[aa].x&&ya<n/2){
				if(ya+1==n/2){
					int k;
					for(k=1;vis[a[aa+k].no];k++);
					if(max(a[aa].y,a[aa].z)==a[aa].y){
						if(a[aa].x<a[aa].y+a[aa+k].x&&yb<n/2){
							vis[a[aa].no]=1;
							ans+=a[aa].y;
							continue;
						}
					}
					else{
						if(a[aa].x<a[aa].y+a[aa+k].x&&yc<n/2){
							vis[a[aa].no]=1;
							ans+=a[aa].z;
							continue;
						}
					}
				}
				vis[a[aa].no]=1;
				ans+=a[aa].x;
				aa++;
				ya++;
			}
			else if(max(a[aa].x,max(b[bb].y,c[cc].z))!=b[bb].y&&min(a[aa].x,min(b[bb].y,c[cc].z))!=b[bb].y&&yb<n/2){
				if(yb+1==n/2){
					int k;
					for(k=1;vis[b[bb+k].no];k++);
					if(max(b[bb].x,b[bb].z)==b[bb].x){
						if(b[bb].y<b[bb].x+b[bb+k].y&&ya<n/2){
							vis[b[bb].no]=1;
							ans+=b[bb].x;
							continue;
						}
					}
					else{
						if(b[bb].y<b[bb].z+b[bb+k].y&&yc<n/2){
							vis[b[bb].no]=1;
							ans+=b[bb].z;
							continue;
						}
					}
				}
				vis[b[bb].no]=1;
				ans+=b[bb].y;
				bb++;
				yb++;
			}
			else if(max(a[aa].x,max(b[bb].y,c[cc].z))!=c[cc].z&&min(a[aa].x,min(b[bb].y,c[cc].z))!=c[cc].z&&yc<n/2){
				if(yc+1==n/2){
					int k;
					for(k=1;vis[c[cc+k].no];k++);
					if(max(c[cc].x,c[cc].y)==c[cc].x){
						if(c[cc].z<c[cc].x+c[cc+k].z&&ya<n/2){
							vis[c[cc].no]=1;
							ans+=c[cc].x;
							continue;
						}
					}
					else{
						if(c[cc].z<c[cc].y+c[cc+k].z&&yb<n/2){
							vis[c[cc].no]=1;
							ans+=c[cc].y;
							continue;
						}
					}
				}
				vis[c[cc].no]=1;
				ans+=c[cc].z;
				cc++;
				yc++;
			}
			//还是没有找最小
			else if(min(a[aa].x,min(b[bb].y,c[cc].z))==a[aa].x){
				if(ya+1==n/2){
					int k;
					for(k=1;vis[a[aa+k].no];k++);
					if(max(a[aa].y,a[aa].z)==a[aa].y){
						if(a[aa].x<a[aa].y+a[aa+k].x&&yb<n/2){
							vis[a[aa].no]=1;
							ans+=a[aa].y;
							continue;
						}
					}
					else{
						if(a[aa].x<a[aa].y+a[aa+k].x&&yc<n/2){
							vis[a[aa].no]=1;
							ans+=a[aa].z;
							continue;
						}
					}
				}
				vis[a[aa].no]=1;
				ans+=a[aa].x;
				aa++;
				ya++;
			}
			else if(min(a[aa].x,min(b[bb].y,c[cc].z))==b[bb].y){
				if(yb+1==n/2){
					int k;
					for(k=1;vis[b[bb+k].no];k++);
					if(max(b[bb].x,b[bb].z)==b[bb].x){
						if(b[bb].y<b[bb].x+b[bb+k].y&&ya<n/2){
							vis[b[bb].no]=1;
							ans+=b[bb].x;
							continue;
						}
					}
					else{
						if(b[bb].y<b[bb].z+b[bb+k].y&&yc<n/2){
							vis[b[bb].no]=1;
							ans+=b[bb].z;
							continue;
						}
					}
				}
				vis[b[bb].no]=1;
				ans+=b[bb].y;
				bb++;
				yb++;
			}
			else if(min(a[aa].x,min(b[bb].y,c[cc].z))==c[cc].z){
				if(yc+1==n/2){
					int k;
					for(k=1;vis[c[cc+k].no];k++);
					if(max(c[cc].x,c[cc].y)==c[cc].x){
						if(c[cc].z<c[cc].x+c[cc+k].z&&ya<n/2){
							vis[c[cc].no]=1;
							ans+=c[cc].x;
							continue;
						}
					}
					else{
						if(c[cc].z<c[cc].y+c[cc+k].z&&yb<n/2){
							vis[c[cc].no]=1;
							ans+=c[cc].y;
							continue;
						}
					}
				}
				vis[c[cc].no]=1;
				ans+=c[cc].z;
				cc++;
				yc++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

