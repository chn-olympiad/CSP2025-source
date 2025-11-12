#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[10105],c[20];
struct tt {
	int to,w,op;
};
vector<tt> p[10104];
int n,m,k,minn=1e9,fom,xiao=1e18;
bool ro[10010][10010];
int fin(int w){
	if(f[w]==w)return w;
	else return f[w]=fin(f[w]);
}
void ksk(int ans,int sta) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
	int sum=1;
	if(sta>n)sum=0;
//	cout<<ans<<endl;
	for(int i=0; i<p[sta].size(); i++) {
		if(p[sta][i].op==0||ro[p[sta][i].to][sta]==1)
			q.push({p[sta][i].w,p[sta][i].to});
	}
	while(!q.empty()) {
		pair<int,int> l=q.top();
		q.pop();
		int fsta=fin(sta),fl=fin(l.second);
		if(fsta!=fl){
			f[fl]=fsta;
			if(l.second<=n)sum++;
		}else continue;
		ans+=l.first;
//		cout<<ans<<' '<<l.second<<' '<<sum<<endl;
		if(sum==n){
			xiao=min(xiao,ans);
			return;
		}
		
		for(int i=0;i<p[l.second].size();i++){
			if(p[l.second][i].op==0||ro[p[l.second][i].to][l.second]==1)
			q.push({p[l.second][i].w,p[l.second][i].to});
		}
	}
	return;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,z,y,x; i<=m; i++) {
		cin>>x>>y>>z;
		p[x].push_back({y,z,0});
		p[y].push_back({x,z,0});
		if(minn>z) {
			minn=z;
			fom=x;
		}
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int x,j=1; j<=n; j++) {
			cin>>x;
			p[j].push_back({n+i,x,1});
			p[n+i].push_back({j,x,1});
		}
	}
	for(int con=0; con<(1<<k); con++) {
		int ans=0;
		for(int i=1; i<=n+k; i++)
			f[i]=i;
		int kk=1,l=con,min1=minn,fom1=fom;
		while(l>0) {
			if((l&1)==1) {
				ans+=c[kk];
				for(int i=0; i<p[n+kk].size(); i++) {
					ro[n+kk][p[n+kk][i].to]=1;
					ro[p[n+kk][i].to][n+kk]=1;
//					cout<<p[n+kk][i].to<<' '<<n+kk<<endl;
					if(min1>p[n+kk][i].w) {
						min1=p[n+kk][i].w;
						fom1=n+kk;
					}
				}
			}
			kk++;
			l>>=1;
		}
		ksk(ans,fom1);
		kk=1,l=con;
		while(l>0) {
			if(l&1==1) {
				ans+=c[kk];
				for(int i=0; i<p[kk].size(); i++) {
					ro[n+kk][p[n+kk][i].to]=0;
					ro[p[n+kk][i].to][n+kk]=0;
				}
			}
			kk++;
			l>>=1;
		}
//		cout<<endl<<endl;
	}
	cout<<xiao<<endl;
}
