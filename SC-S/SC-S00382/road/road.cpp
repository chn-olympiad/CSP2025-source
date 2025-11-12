#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,k;
struct node{int u,v,w;};
vector<node> ve;
bool cmp(node a,node b){return a.w<b.w;};
int f[N];
int zhao(int x){
	if(f[x]==x)return x;
	f[x]=zhao(f[x]);
	return f[x];
}
void lian(int x,int y){
	int p=zhao(x),q=zhao(y);
	f[p]=q;
}
void go(){
	for(int i=1;i<=n;i++)f[i]=i;
	int cnt=0,ans=0;
	for(int i=0;i<m;i++){
		if(cnt==n-1)break;
		int u=ve[i].u,v=ve[i].v;
		if(zhao(u)==zhao(v))continue;
		lian(u,v);
		cnt++;
		ans+=ve[i].w;
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ve.push_back((node){u,v,w});
	}
	sort(ve.begin(),ve.begin()+m,cmp);
	go();
	return 0;
}