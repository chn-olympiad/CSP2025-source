#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int c[15],a[15][10005];
struct jojo{
	int u,v,w;
}BB[2000005],b[2000005];
bool cmp(jojo x,jojo y){
	return x.w<y.w;
}
bool A,B;
int fa[10005];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
vector<vector<int>>v;
vector<int>gg;
void dfs(int now){
	if(now==k+1){
		if(!gg.empty())v.push_back(gg);
		return;
	}
	gg.push_back(now);
	dfs(now+1);
	gg.pop_back();
	dfs(now+1);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;++i){
		fa[i]=i;
	}
	for(int i=1;i<=m;++i){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	A=1;B=0;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		if(c[i]!=0)A=0;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]==0)B=1;
		}
	}
	if(A&&B){
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j){
				if(a[i][j]==0){
					fa[j]=n+i;
				}
				else{
					++m;
					b[m].u=n+i,b[m].v=j,b[m].w=a[i][j];
				}
			}
		}
		sort(b+1,b+1+m,cmp);
		int cnt=1;
		for(int i=1;i<=m;++i){
			int x=b[i].u,y=b[i].v,w=b[i].w;
			x=find(x),y=find(y);
			if(x==y)continue;
			ans+=w;fa[x]=y;
			if(++cnt==n)break;
		}
		cout<<ans<<endl;
	}
	dfs(1);
	sort(b+1,b+1+m,cmp);
	int ansans=1e9;
	for(auto ve:v){
//		for(int i=1;i<=m;++i){
//			cout<<b[i].u<<' '<<b[i].v<<' '<<b[i].w<<endl;
//		}cout<<endl;
		for(int i=1;i<=m;++i){
			BB[i]=b[i];
		}
		int mm=m;ans=0;
		for(int i=1;i<=n+k;++i)fa[i]=i;
		for(auto i:ve){
//			cout<<i<<' ';
			ans+=c[i];
			for(int j=1;j<=n;++j){
				++mm;
				BB[mm].u=n+i,BB[mm].v=j,BB[mm].w=a[i][j];
				for(int q=1;q<=mm;++q){
					if(BB[mm].w<BB[q].w){
						for(int k=mm;k>q;--k){
							swap(BB[k],BB[k-1]);
						}
						break;
					}
				}
			}
			
		}
//		cout<<endl;
//		for(int i=1;i<=mm;++i){
//			cout<<BB[i].u<<' '<<BB[i].v<<' '<<BB[i].w<<endl;
//		}
		int cnt=0;
		for(int i=1;i<=mm;++i){
			int u=BB[i].u,v=BB[i].v,w=BB[i].w;
			int x=find(u),y=find(v);
			if(x==y)continue;
			fa[x]=y;ans+=w;
//			cout<<u<<' '<<v<<' '<<w<<endl;
			if(++cnt==n+ve.size())break;
		}
		ansans=min(ans,ansans);
//		cout<<ans<<endl<<endl;
	}
	cout<<ansans<<endl;
	return 0;
}
