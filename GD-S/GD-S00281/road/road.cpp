#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans,fa[30005],sum,c[105],d[105][10005],vis[15];
struct edge{
	int x,y,z;
}a[1000005];
vector<int> ned1;
vector<pair<pair<int,int>,int> > ned2,ned3;
int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return x;
}
void merge(int x,int y){
	int a=find(x),b=find(y);
	fa[a]=b;
	return;
}
bool cmp(edge a,edge b){return a.z<b.z;}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		if(find(a[i].x)!=find(a[i].y)){
			ans+=a[i].z;
			merge(a[i].x,a[i].y);
			ned2.push_back({{a[i].x,a[i].y},a[i].z});
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>d[i][j];
	}
	for(int i=1;i<=k;i++){
		sum=0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		ned3.clear();
		for(int j=0;j<ned2.size();j++) a[j+1].x=ned2[j].first.first,a[j+1].y=ned2[j].first.second,a[j+1].z=ned2[j].second;
		for(int j=1;j<=n;j++) a[j+ned2.size()].x=n+i,a[j+ned2.size()].y=j,a[j+ned2.size()].z=d[i][j];
		sort(a+1,a+1+n+ned2.size(),cmp);
		for(int j=1;j<=n+k;j++) fa[j]=j; 
		for(int j=1;j<=n+ned2.size();j++){
			if(find(a[j].x)!=find(a[j].y)){
				if(a[j].x>n&&!vis[a[j].x-n]){
					sum+=c[a[j].x-n];
					vis[a[j].x-n]=1;
				}
				sum+=a[j].z;
				merge(a[j].x,a[j].y);
				ned3.push_back({{a[j].x,a[j].y},a[j].z});
			}
		}  
		if(sum<ans){
			ned2.clear();
			for(int j=0;j<ned3.size();j++) ned2.push_back({{ned3[j].first.first,ned3[j].first.second},ned3[j].second});
			ned1.push_back(i);
			ans=sum;
		}
	}
	cout<<ans<<endl;
	return 0;
}
