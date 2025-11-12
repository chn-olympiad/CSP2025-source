#include <iostream>
#include <algorithm>
using namespace std;
inline int read(){
	int f=1,s=0;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-'){
			f=-1;
		}
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		s=s*10+t-'0';
		t=getchar();
	}
	return f*s;
}
const int N=2e6;
struct node{
	int x,y,dist;
}edge[N];
int n,k,m,vis[N],vis2[20],ans,w[20];
bool cmp(node a,node b){
	return a.dist<b.dist;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		edge[i].x=read(),edge[i].y=read(),edge[i].dist=read();
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		w[i]=read();
		for(int j=1;j<=n;j++){
			int o=read();
			cnt++;
			edge[cnt].x=m+i;
			edge[cnt].y=j;
			edge[cnt].dist=w[i]+o;
		}
	}
	sort(edge+1,edge+cnt+1,cmp);
	vis[1]=1;
	for(int i=1;i<=n+k;i++){
		if(!vis[i]) continue;
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				flag=false;
				break;
			}
		} 
		if(flag){
			break;
		}
		for(int j=1;j<=cnt;j++){
			int to=0; 
			if(edge[j].x!=i&&edge[j].y!=i){
				continue;
			}else{
				if(edge[j].x==i){
					to=edge[j].y;
				}else{
					to=edge[j].x;
				}
			}
			if(to<=n){
				if(vis[to]){
					continue;
				}
			}else{
				if(vis2[to-n]){
					continue;
				}
			}
			if(j<=n){
				ans+=edge[j].dist;
			}else{
				ans+=edge[j].dist-w[j-n];
			}
		}
	}
	cout<<ans;
	return 0;
}
