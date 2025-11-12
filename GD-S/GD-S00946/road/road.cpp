#include<bits/stdc++.h>
using namespace std;
void op(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
int cnt=1,n,m,ans=0,k,a[15][10006];
struct tt{
	int l,r,z;
};
int in[1000006],in1[1000006],c[15][1000006];
vector<tt> v;
vector<int> edge[100006];
bool cmp(tt a,tt b){
	return(a.z<b.z);
}
bool vis[1000006],vis1[1000006];
bool cheek(int x,int y){
	queue<int> q;
	int cnt1=cnt+1;
	for(int i=1;i<=n;i++)in1[i]=in[i],vis1[i]=vis[i];
	in1[y]++;
	vis1[y]=1;
	vis1[x]=1;
	for(int i=1;i<=n;i++){
		if(in1[i]==0&&vis1[i])q.push(i);
	}
	while(!q.empty()){
		int id=q.front();
		q.pop();
		cnt1--;
		for(int to:edge[id]){
			in1[to]--;
			if(in1[to]==0&&vis1[to]){
				q.push(to);
			}
		}
	}
	return (cnt1!=0);
}
int main(){
	op();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		edge[x].push_back(y);
		edge[y].push_back(x);
		v.push_back({x,y,z});
		v.push_back({y,x,z});
	}
	for(int i=1;i<=k;i++){
		m++;
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
			edge[m].push_back(j);
			edge[j].push_back(m);
			v.push_back({j,m,c[i][j]});
			v.push_back({m,j,c[i][j]});
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		if(cheek(v[i].l,v[i].r)){
			continue;
		}
		in[v[i].r]++;
		vis[v[i].l]=vis[v[i].r]=1;
		cnt++;
		ans+=v[i].z;
		if(cnt==n)break;
	}
	cout<<ans;
	return 0;
}
