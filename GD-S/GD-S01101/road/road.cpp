#include<bits/stdc++.h>
using namespace std;
const int kMaxn=1e5+10;

int n,m,k;
long long ans=0;
int a[20][kMaxn];
int f[kMaxn];
bool ok[kMaxn];

priority_queue< pair<int,pair<int,pair<int,int> > >,vector<pair<int,pair<int,pair<int,int> > > >, less<pair<int,pair<int,pair<int,int> > > > >q;

struct asd{
	int a[kMaxn];
	int fa;
	int sum;
	int c;
	int w;
	int s;
	priority_queue< pair<int,int>,vector<pair<int,int> >, less<pair<int,int> > >q;
}kk[20];

int root(int x){
	if(f[x]==x)return x;
	else return f[x]=root(f[x]);
}

int main(){
	
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	pair<int,pair<int,pair<int,int> > >p;
	
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		p.first=w;p.second.first=u;p.second.second.first=v;p.second.second.second=0;
		q.push(p);
	}
	for(int i=1;i<=k;i++){
		cin>>kk[i].c;
		for(int j=1;j<=n;j++){
			
			cin>>w;
			kk[i].a[j]=w;
			p.first=w;
			p.second.first=kMaxn+i;
			p.second.second.first=j;
			p.second.second.second=i;
			
		}
		
	}
	pair<int,int>pp;
	int ak;
	while(!q.empty()){
		p=q.top();
		q.pop();
		w=p.first;u=p.second.first;v=p.second.second.first;
		ak=p.second.second.second;
		if(u>=kMaxn){
			int kkk=u-kMaxn;
			if(kk[kkk].sum==0){
				kk[kkk].fa=root(v);
				kk[kkk].sum++;
				kk[kkk].w=w;
			}else{
				p.first=kk[kkk].w+w+kk[kkk].c;
				p.second.first=kk[kkk].fa;
				p.second.second.first=v;
				p.second.second.second=kkk;
				if(kk[ak].s>=1){
					pp.first=w;
					pp.second=v;
					kk[kkk].q.push(pp);
				}
				
				kk[kkk].sum++;
				q.push(p);
			}

		}else{
			
			int fu=root(u),fv=root(v);
			if(fu!=fv){
				f[fv]=fu;
				ans+=w;
				if(ak>0){
					kk[ak].s++;
					int asd=q.top().first;
					if(kk[ak].sum>2){
						while(!kk[ak].q.empty()){
							pp=kk[ak].q.top();
							kk[ak].q.pop();
							if(pp.first<=asd){
								if(root(pp.second)!=root(kk[ak].fa)){
									f[root(pp.second)]=root(kk[ak].fa);
									ans+=pp.first;
								}
							}else{
								kk[ak].q.push(pp);
								break;
							}
						}
					}
				}
			}
			
		}
	}
	
	cout<<ans;
	return 0; 
}
