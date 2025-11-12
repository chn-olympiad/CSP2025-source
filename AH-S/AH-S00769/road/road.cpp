#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node{
	int f,t,w;
}edge[1100000];
bool cmp(node a,node b){
	return a.w<b.w;
}
int s[1000010];
int find_set(int p){
	if(s[p]==p)return p;
	return s[p]=find_set(s[p]);
}
int c[20],a[20][10010];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].f>>edge[i].t>>edge[i].w;
	}
	int sssum=0;
	for(int i=1;i<=k;i++){
		cin>>c[k];
		sssum+=c[k];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			m++;
			edge[m]={n+i,j,a[i][j]};
		}
	}
	n+=k;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n;i++)s[i]=i;
	int cnt=0;
	int ans=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1)break;
		if(find_set(edge[i].f)==find_set(edge[i].t))continue;
		ans+=edge[i].w;
		s[max(edge[i].f,edge[i].t)]=find_set(min(edge[i].t,edge[i].f));
		cnt++;
	}
	cout<<ans<<'\n';
//	if(k==0){
//		sort(edge+1,edge+m+1,cmp);
//		for(int i=1;i<=n;i++)s[i]=i;
//		int cnt=0;
//		int ans=0;
//		for(int i=1;i<=m;i++){
//			if(cnt==n-1)break;
//			if(find_set(edge[i].f)==find_set(edge[i].t))continue;
//			ans+=edge[i].w;
//			s[max(edge[i].f,edge[i].t)]=find_set(min(edge[i].t,edge[i].f));
//			cnt++;
//		}
//		cout<<ans<<'\n';
//		return 0;
//	}
	return 0;
}
