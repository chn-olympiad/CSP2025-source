#include <iostream>
#include <queue>
using namespace std;
constexpr int N=100005;
struct node{
	int id,w,c;
	bool operator<(const node& __x) const{ 
		return __x.c>c;
	}
};
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	while(t--){
		int n,x[N]={},y[N]={},z[N]={};
		long long ans=0;
		priority_queue<node> a,b,c;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>x[i]>>y[i]>>z[i];
			if(x[i]>=y[i]&&x[i]>=z[i]) a.push(node{i,x[i],min(x[i]-y[i],x[i]-z[i])});
			else if(y[i]>=x[i]&&y[i]>=z[i]) b.push(node{i,y[i],min(y[i]-x[i],y[i]-z[i])});
			else c.push(node{i,z[i],min(z[i]-y[i],z[i]-x[i])});
		}
		if(a.size()>n/2){
			for(int i=1;i<=n/2;++i){
				ans+=a.top().w;
				a.pop();
			}
			while(!a.empty()){
				node u=a.top();
				if(y[u.id]>z[u.id]) b.push(node{0,y[u.id],0});
				else c.push(node{0,z[u.id],0});
				a.pop();
			}
			while(!b.empty()){
				ans+=b.top().w;
				b.pop();
			}
			while(!c.empty()){
				ans+=c.top().w;
				c.pop();
			}
		}else if(b.size()>n/2){
			for(int i=1;i<=n/2;++i){
				ans+=b.top().w;
				b.pop();
			}
			while(!b.empty()){
				node u=b.top();
				if(x[u.id]>z[u.id]) a.push(node{0,x[u.id],0});
				else c.push(node{0,z[u.id],0});
				b.pop();
			}
			while(!a.empty()){
				ans+=a.top().w;
				a.pop();
			}
			while(!c.empty()){
				ans+=c.top().w;
				c.pop();
			}
		}else if(c.size()>n/2){
			for(int i=1;i<=n/2;++i){
				ans+=c.top().w;
				c.pop();
			}
			while(!c.empty()){
				node u=c.top();
				if(x[u.id]>y[u.id]) a.push(node{0,x[u.id],0});
				else b.push(node{0,y[u.id],0});
				c.pop();
			}
			while(!b.empty()){
				ans+=b.top().w;
				b.pop();
			}
			while(!a.empty()){
				ans+=a.top().w;
				a.pop();
			}
		}else{
			while(!a.empty()){
				ans+=a.top().w;
				a.pop();
			}
			while(!b.empty()){
				ans+=b.top().w;
				b.pop();
			}
			while(!c.empty()){
				ans+=c.top().w;
				c.pop();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
