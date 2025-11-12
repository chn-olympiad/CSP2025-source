#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
//rp++
//CCFrangwoguoba
//I love CCF very much! 
//I love CCF very much! 
//I love CCF very much! 
int t,n,a[N][4],ans;

struct node{
	int id,p;
	friend bool operator<(node x,node y){
		if(x.p==1) return a[x.id][1]-max(a[x.id][2],a[x.id][3])>a[y.id][1]-max(a[y.id][2],a[y.id][3]);
		else if(x.p==2) return a[x.id][2]-max(a[x.id][1],a[x.id][3])>a[y.id][2]-max(a[y.id][1],a[y.id][3]);
		else return a[x.id][3]-max(a[x.id][1],a[x.id][2])>a[y.id][3]-max(a[y.id][1],a[y.id][2]);
	}
};

priority_queue<node> p1,p2,p3;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		while(!p1.empty()) p1.pop();
		while(!p2.empty()) p2.pop();
		while(!p3.empty()) p3.pop();
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				if(p1.size()<n/2){
					p1.push({i,1});
				}else{
					int x=p1.top().id;
					int y=a[x][1]-max(a[x][2],a[x][3]);
					int z=a[i][1]-max(a[i][2],a[i][3]);
					if(y>z){
						if(a[i][2]>=a[i][3]){
							p2.push({i,2});
						}else{
							p3.push({i,3});
						}
					}else{
						p1.pop();
						p1.push({i,1});
						if(a[x][2]>=a[x][3]){
							p2.push({x,2});
						}else{
							p3.push({x,3});
						}
					}
				}
			}else if(a[i][2]>=a[i][3]){
				if(p2.size()<n/2){
					p2.push({i,2});
				}else{
					int x=p2.top().id;
					int y=a[x][2]-max(a[x][1],a[x][3]);
					int z=a[i][2]-max(a[i][1],a[i][3]);
					if(y>z){
						if(a[i][1]>=a[i][3]){
							p1.push({i,1});
						}else{
							p3.push({i,3});
						}
					}else{
						p2.pop();
						p2.push({i,2});
						if(a[x][1]>=a[x][3]){
							p1.push({x,1});
						}else{
							p3.push({x,3});
						}
					}
				}
			}else{
				if(p3.size()<n/2){
					p3.push({i,3});
				}else{
					int x=p3.top().id;
					int y=a[x][3]-max(a[x][1],a[x][2]);
					int z=a[i][3]-max(a[i][1],a[i][2]);
					if(y>z){
						if(a[i][1]>=a[i][2]){
							p1.push({i,1});
						}else{
							p2.push({i,2});
						}
					}else{
						p3.pop();
						p3.push({i,3});
						if(a[x][1]>=a[x][2]){
							p1.push({x,1});
						}else{
							p2.push({x,2});
						}
					}
				}
			}
		}
		while(!p1.empty()){
			int x=p1.top().id;
			p1.pop();
			ans+=a[x][1];
		}
		while(!p2.empty()){
			int x=p2.top().id;
			p2.pop();
			ans+=a[x][2];
		}
		while(!p3.empty()){
			int x=p3.top().id;
			p3.pop();
			ans+=a[x][3];
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
