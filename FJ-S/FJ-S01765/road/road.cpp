#include<bits/stdc++.h>
using namespace std;
long long h,t,n,m,a,b,dis[20000],q,s,f,l,r1,r2,x[1500000],y[1500000];
struct czx{
	long long v,w;
};
vector<czx> u[20000];
priority_queue<long long,vector<long long>,greater<long long>> p;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
		cin>>n>>m>>h;
		for(int i=1;i<=m;i++){
			cin>>x[i]>>y[i]>>q;
			u[x[i]].push_back({i,q});
			u[y[i]].push_back({i,q});
		}
		for(int i=1;i<=h;i++){
			cin>>a;
			for(int j=1;j<=n;j++){
				cin>>q;
				m++;
				x[m]=n+i;
				y[m]=j;
				u[n+i].push_back({m,q});
				u[j].push_back({m,q});
			}
		}
		n+=h;
		s=1;
		for(int i=1;i<n;i++){
			dis[s]=1;
			l=u[s].size();
			for(int j=0;j<l;j++){
				if(dis[x[u[s][j].v]]==0||dis[y[u[s][j].v]]==0){
					r1=u[s][j].v;
					r2=u[s][j].w;
					p.push(r2*10000000+r1);
				}
			}	
			while(dis[x[p.top()%10000000]]==1&&dis[y[p.top()%10000000]]==1){
				p.pop();
			}
			f=p.top()%10000000;	
			if(dis[x[f]]==1)
				s=y[f];
			else
				s=x[f];
			t+=p.top()/10000000;
			p.pop();
		}
		cout<<t<<endl;
	return 0;
}