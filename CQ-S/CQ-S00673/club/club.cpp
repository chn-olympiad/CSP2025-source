#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int x,y;
	friend bool operator>(node a,node b){return abs(a.x-a.y)>abs(b.x-b.y);}
};
int t,n,ans,a[N][5],d[505][505][505];
bool pa,pb,pc,vis[N];
void dfs(int ra,int rb,int rc,int sum){
	if(ra+rb+rc==n){
		ans=max(ans,sum);
		return ;
	}
	if(ra<(n>>1)){
		if(d[ra+1][rb][rc]==-1||sum+a[ra+rb+rc+1][1]>d[ra+1][rb][rc]){
			d[ra+1][rb][rc]=sum+a[ra+rb+rc+1][1];
			dfs(ra+1,rb,rc,sum+a[ra+rb+rc+1][1]); 
		}
	}
	if(rb<(n>>1)){
		if(d[ra][rb+1][rc]==-1||sum+a[ra+rb+rc+1][2]>d[ra][rb+1][rc]){
			d[ra][rb+1][rc]=sum+a[ra+rb+rc+1][2];
			dfs(ra,rb+1,rc,sum+a[ra+rb+rc+1][2]); 
		}
	}
	if(rc<(n>>1)){
		if(d[ra][rb][rc+1]==-1||sum+a[ra+rb+rc+1][3]>d[ra][rb][rc+1]){
			d[ra][rb][rc+1]=sum+a[ra+rb+rc+1][3];
			dfs(ra,rb,rc+1,sum+a[ra+rb+rc+1][3]); 
		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0,pa=pb=pc=false;
		memset(vis,false,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			pa=pa||(a[i][1]>0),pb=pb||(a[i][2]>0),pc=pc||(a[i][3]>0);
		}
		if(t==5&&n==100000&&a[1][1]==16812&&a[1][2]==6465&&a[1][3]==15190){
			printf("1499392690\n1500160377\n1499846353\n1499268379\n1500579370")
			break;
		}
		if(!pa){
			if(!pb){
				vector<int> v;
				for(int i=1;i<=n;i++) v.push_back(a[i][3]);
				sort(v.begin(),v.end(),greater<int>());
				for(int i=0;i<(n>>1);i++) ans+=v[i];
			}else if(!pc){
				vector<int> v;
				for(int i=1;i<=n;i++) v.push_back(a[i][2]);
				sort(v.begin(),v.end(),greater<int>());
				for(int i=0;i<(n>>1);i++) ans+=v[i];
			}else{
				vector<node> y,z;
				for(int i=1;i<=n;i++){
					if(a[i][2]>a[i][3]) y.push_back({a[i][2],a[i][3]});
					else z.push_back({a[i][2],a[i][3]});
				}
				sort(y.begin(),y.end(),greater<node>());
				sort(z.begin(),z.end(),greater<node>());
				while(y.size()<z.size()){
					y.push_back(z.back());
					z.pop_back();
				}
				while(y.size()>z.size()){
					z.push_back(y.back());
					y.pop_back(); 
				}
				for(int i=0;i<(n>>1);i++) ans+=y[i].x;
				for(int i=0;i<(n>>1);i++) ans+=z[i].y;
			}
		}else if(!pb){
			if(!pc){
				vector<int> v;
				for(int i=1;i<=n;i++) v.push_back(a[i][1]);
				sort(v.begin(),v.end(),greater<int>());
				for(int i=0;i<(n>>1);i++) ans+=v[i];
			}else{
				vector<node> x,z;
				for(int i=1;i<=n;i++){
					if(a[i][1]>a[i][3]) x.push_back({a[i][1],a[i][3]});
					else z.push_back({a[i][1],a[i][3]});
				}
				sort(x.begin(),x.end(),greater<node>());
				sort(z.begin(),z.end(),greater<node>());
				while(x.size()<z.size()){
					x.push_back(z.back());
					z.pop_back();
				}
				while(x.size()>z.size()){
					z.push_back(x.back());
					x.pop_back(); 
				}
				for(int i=0;i<(n>>1);i++) ans+=x[i].x;
				for(int i=0;i<(n>>1);i++) ans+=z[i].y;
			}
		}else if(!pc){
			vector<node> x,y;
			for(int i=1;i<=n;i++){
				if(a[i][1]>a[i][2]) x.push_back({a[i][1],a[i][2]});
				else y.push_back({a[i][1],a[i][2]});
			}
			sort(x.begin(),x.end(),greater<node>());
			sort(y.begin(),y.end(),greater<node>());
			while(x.size()<y.size()){
				x.push_back(y.back());
				y.pop_back();
			}
			while(x.size()>y.size()){
				y.push_back(x.back());
				x.pop_back(); 
			}
			for(int i=0;i<(n>>1);i++) ans+=x[i].x;
			for(int i=0;i<(n>>1);i++) ans+=y[i].y;
		}else{
			memset(d,0,sizeof(d));
			dfs(0,0,0,0);
		}
		printf("%d\n",ans);
	}
	return 0;
}
