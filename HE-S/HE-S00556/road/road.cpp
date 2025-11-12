#include<bits/stdc++.h>
using namespace std;
#define N 10019 
#define M 1100019
#define int long long 
struct qwq{
	int fr,to,di;
}a[M];
int n,m,k,fa[N],ans,b,c[20];
bool vi[N];
int gf(int x){
	if(fa[x]!=x) fa[x]=gf(fa[x]);
	return fa[x];
}
bool cmp(qwq a,qwq b){
	return a.di<b.di;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].fr>>a[i].to>>a[i].di;
	for(int i=1;i<=n;i++) fa[i]=i;
	if(k==0){
		sort(a+1,a+m+1,cmp);
		int cnt=0;
		for(int i=1;i<=m;i++){
			int u=a[i].fr,v=a[i].to,w=a[i].di;
			if(gf(u)!=gf(v)){
				cnt++;
				ans+=w;
				fa[gf(u)]=gf(v);
			} 
			if(cnt==n-1){
				cout<<ans;
				return 0;
			}
		}
	}
	int c2=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>b;
			c2++;
			a[m+c2].fr=n+c2;
			a[m+c2].to=j;
			a[m+c2].di=b;
		}
	}
	sort(a+1,a+m+c2+1,cmp);
	int cnt=0;
	cout<<m;
	for(int i=1;i<=m;i++){
		cout<<'\n';
		int u=a[i].fr,v=a[i].to,w=a[i].di;
		if(u>v) swap(u,v);
		vi[u]=1,vi[v]=1;
		if(gf(u)!=gf(v) ||!(vi[u] || v>n)){
			cnt++;
			ans+=w;
			fa[gf(u)]=gf(v);
		}
		if(cnt==n-1){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
