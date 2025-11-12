#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{int u,v,w;}p[1000100],res[11];
bool cmp(node x,node y){return x.w<y.w;}
int n,m,k,fa[10021],cnt,ans,sum[11],now[11],c[10021],a;
vector<pair<pair<int,int>,pair<int,int> > > beixuan;//w,u,v,pos
vector<node> st[11];
bool fl[11];
int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
void merge(int x,int y){fa[find(x)]=find(y);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>p[i].u>>p[i].v>>p[i].w;
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(find(p[i].u)==find(p[i].v))continue;
		merge(p[i].u,p[i].v),ans+=p[i].w;
		p[++cnt].u=p[i].u,p[cnt].v=p[i].v,p[cnt].w=p[i].w;
	}//cnt=n-1,cnt<=i
	if(k==0){
		cout<<ans;
		return 0;
	}
	cout<<ans<<' ';
//	for(int j=1;j<=k;j++){
//		cin>>c[j],flag=0;
//		if(c[j])f=0;
//		for(int i=1;i<=n;i++){
//			cin>>a[j][i];
//			if(!a[j][i])flag=1;
//		}
//		if(!flag)f=0;
//	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a,p[i*n+j-1].u=j,p[i*n+j-1].v=i+n,p[i*n+j-1].w=a;
		}
	}
	ans=0; 
	sort(p+1,p+(k*n+n-1)+1,cmp);
	for(int i=1;i<=k+n;i++)fa[i]=i;
	for(int i=1;i<=k*n+n-1;i++){
		beixuan.clear();
		for(int j=1;j<=k;j++){
			for(;now[j]<st[j].size();now[j]++){
				if(!fl[p[i].v-n]){
					if(c[j]+st[j][now[j]].w<=p[i].w){
						if(find(st[j][now[j]].u)==find(st[j][now[j]].v))continue;
						beixuan.push_back({{st[j][now[j]].w+c[j],st[j][now[j]].u},{st[j][now[j]].v,1}});
					}else break;
				}else{
					if(st[j][now[j]].w<=p[i].w){
						if(find(st[j][now[j]].u)==find(st[j][now[j]].v))continue;
						beixuan.push_back({{st[j][now[j]].w,st[j][now[j]].u},{st[j][now[j]].v,0}});
					}else break;
				}
			}
		}
		if(beixuan.size()){
			sort(beixuan.begin(),beixuan.end());
			for(auto x:beixuan){
				if(find(x.first.second)==find(x.second.first))continue;
				if(!fl[x.second.first-n])merge(x.first.second,x.second.first),ans+=x.first.first,sum[x.second.first-n]++,res[x.second.first-n]={x.first.second,x.second.first,x.first.first},fl[x.second.first-n]=1;
				else merge(x.first.second,x.second.first),ans+=x.first.first-(x.second.second?c[x.second.first-n]:0),sum[x.second.first-n]++,res[x.second.first-n]={x.first.second,x.second.first,x.first.first},fl[x.second.first-n]=1;
				cout<<x.first.second<<' '<<x.second.first<<' '<<x.first.first<<" 1 \n";
			}
		}
		if(p[i].v>n){
			if(!fl[p[i].v-n]){
				if(c[p[i].v-n]+p[i].w<=p[i+1].w){
					if(find(p[i].u)==find(p[i].v))continue;
					merge(p[i].u,p[i].v),ans+=p[i].w,sum[p[i].v-n]++,res[p[i].v-n]=p[i],fl[p[i].v-n]=1;
					cout<<p[i].u<<' '<<p[i].v<<' '<<p[i].w<<" 2 \n";
				}else st[p[i].v-n].push_back(p[i]);
			}else{
				if(find(p[i].u)==find(p[i].v))continue;
				merge(p[i].u,p[i].v),ans+=p[i].w,sum[p[i].v-n]++,res[p[i].v-n]=p[i];
				cout<<p[i].u<<' '<<p[i].v<<' '<<p[i].w<<" 3 \n";
			}
		}else{
			if(find(p[i].u)==find(p[i].v))continue;
			merge(p[i].u,p[i].v),ans+=p[i].w;
			cout<<p[i].u<<' '<<p[i].v<<'\n';
		}
	}
	for(int i=1;i<=k;i++){
		if(sum[i]==1)ans-=res[i].w;
	}
	cout<<ans;
}
