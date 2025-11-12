#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4+3;
int city[12],cnt=0,Rd[300005],vis[maxn];
struct node{
	int sum,u,v,index;
}judge[5000009];
int n,m,k;
bool cmp(node a,node b){
	return a.sum<b.sum;
}
void solve(){
	int ans=0,num=0,sum;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		judge[++cnt].sum=w;
		judge[cnt].u=u;
		judge[cnt].v=v;
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>city[i];
		int w;
		for(int j=1;j<=n;j++){
			cin>>w;
			judge[++cnt].sum=w+city[i];
			judge[cnt].u=i;
			judge[cnt].v=j;
			judge[cnt].index=i;
		}
	}
	sort(judge+1,judge+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		ans+=judge[i].sum-(vis[judge[i].index]!=0)*city[judge[i].index];
		vis[judge[i].index]++;
		if(judge[i].u<=n)
			num++;
		if(judge[i].v<=n)
			num++;
		Rd[judge[i].u]++;
		Rd[judge[i].v]++;
		if(num>=(n-1)*2){
			cout<<ans;
			return ;
		}
	
	}
	return ;
}
void solve1(){
	int ans=0,num=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		judge[++cnt].sum=w;
		judge[cnt].u=u;
		judge[cnt].v=v;
	}
	sort(judge+1,judge+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		ans+=judge[i].sum;
		num+=2;
		if(num>=(n-1)*2){
			cout<<ans;
			break;
		}
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	if(k!=1)
	solve();
	else
	solve1();
	return 0;
} 
