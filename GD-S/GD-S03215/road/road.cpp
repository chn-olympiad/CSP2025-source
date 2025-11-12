#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans=2e18,c[15],to[15][10085],bin[10085],tot,t=-1,nows[15];
pair<int,pair<int,int> >b[1000085];
bitset<10085>num,a[15];
vector<pair<int,pair<int,int> > >l[15];
int find(int x){
	if(x==bin[x]) return x;
	return bin[x]=find(bin[x]);
}
pair<int,pair<int,int> >get_min(){
	int s=-1,minns=2e18;
	for(int i=0;i<=k;i++) if(num[i]) if(nows[i]<l[i].size()&&minns>l[i][nows[i]].first) minns=l[i][nows[i]].first,s=i;
	nows[s]++;
	return l[s][nows[s]-1];
}
int kru(int s,int o){
	memset(nows,0,sizeof(nows));
	int res=0,c=1;
	for(int i=1;i<=n+k;i++) bin[i]=i;
	while(c<s+n){
		pair<int,pair<int,int> >minn=get_min();
		int u=minn.second.first,v=minn.second.second,w=minn.first;
		if(find(u)!=find(v)) res+=w,c++,bin[find(u)]=find(v);
		if(o+res>=ans) return 2e18;
	}
	return res;
}
void dfs(int pos,int y=0){
	if(pos==k+1){
		int q=0;
		for(int i=1;i<=k;i++) q+=num[i]*c[i];
		q+=kru(y,q);
		ans=min(ans,q);
		return;
	}
	num[pos]=0;
	dfs(pos+1,y);
	num[pos]=1;
	dfs(pos+1,y+1);
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	num[0]=1;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) bin[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		b[i]={w,{u,v}};
	}
	int P=0;
	sort(b+1,b+1+m);
	for(int i=1;i<=m;i++){
		int u=b[i].second.first,v=b[i].second.second;
		u=find(u),v=find(v);
		if(u!=v) tot+=b[i].first,bin[u]=v,l[0].push_back(b[i]),P++;
		if(P+1==n) break;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>to[i][j],l[i].push_back({to[i][j],{i+n,j}});
		sort(l[i].begin(),l[i].end());
	}
	dfs(1);
	cout<<ans;
	return 0;
}
