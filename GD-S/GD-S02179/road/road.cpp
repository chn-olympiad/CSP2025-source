#include<bits/stdc++.h>
using namespace std;
struct f{
	int from,to,worth;
}a[1000005];
long long ans=0;
int cnt=0;
int n,m,k;
bool cmd(f x,f y){
	return x.worth<y.worth;
}
int fa[10005];
int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
void un(int x,int y){
	fa[x]=get(fa[y]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	for(int i=1;i<=m;++i){
		int x,y,z;cin>>x>>y>>z;
		a[i].worth=z;
		a[i].from=x;
		a[i].to=y;
	}
	sort(a+1,a+m+1,cmd);
	for(int i=1;i<=k;++i){
		int w;cin>>w;
		for(int j=1;j<=n;++j){
			int x;cin>>x;
		}
	}
	for(int i=1;i<=m;++i){
		if(cnt==n-1)break;
		if(get(a[i].from)!=get(a[i].to)){
			ans+=a[i].worth;
			cnt++;
			un(a[i].from,a[i].to);
		}
	}
	cout<<ans<<endl;
	return 0;
}
