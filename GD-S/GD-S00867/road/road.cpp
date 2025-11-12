#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INS=1e16;
ll msum;
struct vt{
	ll num;
	int to;
};
vector<vt> v[10005];
struct dst{
	vector<vt> dt;
	ll num;
}d[11];
bool cmpd(dst a,dst b){
	return a.num<b.num;
}

struct st{
	int f,x;ll num;
	
};
struct cmp{
	bool operator ()(const st& b,const st& a){
		return b.num>a.num;
	}
};
int n,t,k,m;
ll bfs(){
	ll sum=0;
	ll dnum[10005];
	memset(dnum,-1,sizeof dnum);
	priority_queue<st,vector<st>,cmp> q;
	st be;
	be.f=0;
	be.x=1;
	be.num=0;
	q.push(be);
	while(!q.empty()){
		st p=q.top();
		q.pop();
		//cout<<p.x<<endl;
		if(dnum[p.x]==-1){
			st u;
			u.f=p.x;
			for(int i=0;i<v[p.x].size();i++){
				if(p.f==v[p.x][i].to) continue;
				else{
					u.x=v[p.x][i].to;
					u.num=v[p.x][i].num;
					q.push(u);
				}
				
			}
			dnum[p.x]=p.num;
			sum+=p.num;
		}
		/*else{
			if(p.num<dnum[p.x])	{
				sum=sum+p.num-dnum[p.x];
				dnum[p.x]=p.num;
			}
		}*/
	}
	for(int i=1;i<=n;i++){
		if(dnum[i]==-1){
			
			return INS;
		}
	}
	return sum;
}
ll bfsd(int dx){
	ll sum=0;
	ll dnum[10005];
	memset(dnum,-1,sizeof dnum);
	priority_queue<st,vector<st>,cmp> q;
	st be;
	be.f=0;
	for(int i=0;i<d[dx].dt.size();i++){
			be.x=d[dx].dt[i].to;
			be.num=d[dx].dt[i].num;
			q.push(be);
				
	}
	while(!q.empty()){
		st p=q.top();
		q.pop();
		if(dnum[p.x]==-1){
			st u;
			u.f=p.x;
			for(int i=0;i<v[p.x].size();i++){
				if(p.f==v[p.x][i].to) continue;
				else{
					u.x=v[p.x][i].to;
					u.num=v[p.x][i].num;
					q.push(u);
				}
				
			}
			dnum[p.x]=p.num;
			sum+=p.num;
		}
		else{
			if(p.num<dnum[p.x])	{
				sum=sum+p.num-dnum[p.x];
				dnum[p.x]=p.num;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dnum[i]==-1) return INS;
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y;ll z;
		scanf("%d%d%lld",&x,&y,&z);
		vt vi;
		vi.num=z;
		vi.to=y;
		v[x].push_back(vi);
		vi.to=x;
		v[y].push_back(vi);
	}
	for(int j=1;j<=k;j++){
		scanf("%lld",&d[j].num);
		for(int i=1;i<=n;i++){
			ll z;
			scanf("%lld",&z);
			vt di;
			di.num=z;
			di.to=i;
			d[j].dt.push_back(di);
		}
	}
	msum=bfs();
	for(int i=1;i<=k;i++){
		msum=min(d[i].num+bfsd(i),msum);
	}
	//ll sum=msum;
	/*sort(d+1,d+k+1,cmpd);
	int dl[1005];ll dm[11];ll dq[1001];ll ds[11];
	memset(dm,-1,sizeof dm);
	for(int i=1;i<=n;i++){
		dq[i]=dnum[i];
	}
	vector<int> dj;
	memset(dl,0,sizeof dl);
	for(int i=1;i<=k;i++){
		ll dsum=0,dmsum=0;
		for(int j=0;j<n;j++){
			if(dnum[j+1]>d[i].dt[j].num){
				dsum+=dnum[j+1]-d[i].dt[j].num;
				dmsum+=dq[j+1]-d[i].dt[j].num;
				dj.push_back(j+1);
			}
		}
		if(dsum>d[i].num){
			for(int j=0;j<dj.size();j++){
				if(dl[dj[j]]){
					dm[dl[dj[j]]]-=dq[dj[j]]-dnum[dj[j]];
					dl[dj[j]]=i;
				}
				dnum[dj[j]]=d[i].dt[dj[j]-1].num;
			}
			for(int j=1;j<i;j++){
				if(dm[j]!=-1&&dm[j]<d[j].num){
					msum+=dm[j]-d[j].num;
					for(int o=1;o<=n;o++){
						if(dl[o]==j) dnum[o]=dq[o];
					}
					dm[j]=-1;
				}
			}
			dm[i]=dmsum;
			msum=msum-dsum+d[i].num;
			cout<<dsum<<endl;
		}
		
	}*/
	cout<<msum;
}
