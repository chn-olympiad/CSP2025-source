#include<bits/stdc++.h>
#define fors(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define inf INT_MAX
using namespace std;
const int N=1e5+567;
int t;
typedef pair<int,pair<int,int> > P;
// value i now 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		priority_queue<P,vector<P>,greater<P> >a,b,c;
		int to[N][5]={0};
		int go[N]={0};
		int ans=0,n,m=0;
		cin>>n;
		m=n/2;
		fors(i,1,n){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				ans+=x;
				if(y>=z){
					to[i][1]=2;
					to[i][2]=3;
					a.push({x-y,{i,1}});
					go[i]=y-z;
				}else{
					to[i][1]=3;
					to[i][3]=2;
					a.push({x-z,{i,1}});
					go[i]=z-y;
				}
			}else if(y>=x&&y>=z){
				ans+=y;
				if(x>=z){
					to[i][2]=1;
					to[i][1]=3;
					b.push({y-x,{i,1}});
					go[i]=x-z;
				}else{
					to[i][2]=3;
					to[i][3]=1;
					b.push({y-z,{i,1}});
					go[i]=z-x;
				}
			}else{
				ans+=z;
				if(x>=y){
					to[i][3]=1;
					to[i][1]=2;
					c.push({z-x,{i,1}});
					go[i]=x-y;
				}else{
					to[i][3]=2;
					to[i][2]=1;
					c.push({z-y,{i,1}});
					go[i]=y-x;
				}
			}
		}
		while(a.size()>m||b.size()>m||c.size()>m){
			if(a.size()>m){
				P p=a.top();
				a.pop();
				ans-=p.fi;
				int u=p.se.fi;
				int v=p.se.se;
				if(v==2){
					if(to[u][1]==2){
						b.push({inf,{u,2}});
					}else{
						c.push({inf,{u,2}});
					}
				}else if(v==1){
					if(to[u][1]==2){
						b.push({go[u],{u,2}});
					}else{
						c.push({go[u],{u,2}});
					}
				}
			}else if(b.size()>m){
				P p=b.top();
				b.pop();
				ans-=p.fi;
				int u=p.se.fi;
				int v=p.se.se;
				if(v==2){
					if(to[u][2]==1){
						a.push({inf,{u,2}});
					}else{
						c.push({inf,{u,2}});
					}
				}else if(v==1){
					if(to[u][2]==1){
						a.push({go[u],{u,2}});
					}else{
						c.push({go[u],{u,2}});
					}
				}
			}else{
				P p=c.top();
				c.pop();
				ans-=p.fi;
				int u=p.se.fi;
				int v=p.se.se;
				if(v==2){
					if(to[u][3]==2){
						b.push({inf,{u,2}});
					}else{
						a.push({inf,{u,2}});
					}
				}else if(v==1){
					if(to[u][3]==2){
						b.push({go[u],{u,2}});
					}else{
						a.push({go[u],{u,2}});
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}