#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,m;
long long ans;
struct node{
	int u,v,w;
}a[N];
bool cmp(node x,node y){
	return x.u>y.u;
}
void dfs(int aa,int bb,int cc,int k,long long cnt){
	if(k==n+1){
		ans=max(cnt,ans);
		return ;
	}
	if(aa<m)dfs(aa+1,bb,cc,k+1,cnt+a[k].u);
	if(bb<m)dfs(aa,bb+1,cc,k+1,cnt+a[k].v);
	if(cc<m)dfs(aa,bb,cc+1,k+1,cnt+a[k].w);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		bool f=1; 	
		for(int i=1;i<=n;i++){
			cin>>a[i].u>>a[i].v>>a[i].w;
			if(!(a[i].v==0&&a[i].w==0))f=0;
		}
		m=n>>1;
		if(f){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=m;i++){
				ans+=a[i].u;
			}
		}
		else{	
			dfs(0,0,0,1,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
