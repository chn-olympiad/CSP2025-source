#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll n,m,k,cnt,cnt1,f[N],sum,con;
bool del[N];
struct node{
	ll u,v,w;
	ll S,SS;
}edge[N];
ll find(ll x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
ll mer(ll x,ll y){
	ll r1=find(x);
	ll r2=find(y);
	//cout<<r1<<" "<<r2<<endl;
	if(r1!=r2){
		f[r2]=r1;
		return 1;
	}
	return 0;
}
void add(ll u,ll v,ll w,ll x){
	cnt++;
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].w=w;
	if(u==0||v==0){
		edge[cnt].S=cnt1;
		edge[cnt].SS=x;
	} 
	else edge[cnt].S=-1;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll i,j;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		add(u,v,w,-1);
		//add(v,u,w,-1);
	}
	for(i=1;i<=k;i++){
		++cnt1;
		ll x;
		cin>>x;
		for(j=1;j<=n;j++){
			ll y;
			cin>>y;
			add(0,j,x+y,x);
		}
	}
//	5215664052
//	5206997190
	sort(edge+1,edge+1+cnt,cmp);
	//for(i=1;i<=cnt;i++) cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
	for(i=0;i<=cnt;i++) f[i]=i;
	for(i=1;i<=cnt;i++){
		if(mer(edge[i].u,edge[i].v)){
			//cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
			if(edge[i].u==0){
				con--;
				if(del[edge[i].S]==true) sum-=edge[i].SS;
				del[edge[i].S]=true;
			}
			sum+=edge[i].w;
			con++;
		}
		if(con==n-1) break;
	}
	cout<<sum;
	return 0;
}
/*
4 5 1
1 2 4
1 3 3
2 3 1
3 4 5
1 4 2
1 2 1 3 4
*/
/*
4 5 1
1 2 4
1 3 3
2 3 1
3 4 5
1 4 2
0 2 1 0 7
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
