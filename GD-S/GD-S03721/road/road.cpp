#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[10005],cost[10005];
vector<int> ch; 
struct node{
	int x,y,z;
	bool flag;
};
vector<node> v;
bool cmp(node x,node y){
	return x.z<y.z;
}int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}bool same(int x,int y){
	if(get(x)==get(y)) return true;
	else return false;
}void merge(int x,int y){
	int fax=get(x),fay=get(y);
	if(fax==fay) return;
	fa[fax]=fay;
}long long ans,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v.push_back({x,y,z,false});
	}for(int i=1;i<=n+1;i++) cin>>cost[i];
	for(int i=1;i<=n+1;i++){
		int c;
		cin>>c;
		if(k){
			for(int j=1;j<=n+1;j++){
				v.push_back({i,j,c,true});
			}
		}
	}int chz=0;
	sort(v.begin(),v.end(),cmp);
	map<int,int> mp;
	for(int i=0;i<v.size();i++){
		if(chz==k && v[i].flag && mp[v[i].x]==0) continue;
		if(!same(v[i].x,v[i].y)){
			merge(v[i].x,v[i].y);
			ans+=v[i].z;
			if(v[i].flag && mp[v[i].x]==0){
				ans+=cost[v[i].x];
				mp[v[i].x]=1;
				chz++;
			}
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
