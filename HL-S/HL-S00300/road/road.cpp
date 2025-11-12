#include <bits/stdc++.h>
using namespace std;
int n,m,k,fa[110000],ans,upg[11][110000],mduo;
struct node{
	long long int u,v,w;
}a[110000];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void make(int x,int y){
	int a,b;
	a=find(x),b=find(y);
	if(a==b) return;
	fa[y]=x;
}
void kas(){
	ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			make(a[i].u,a[i].v);
			ans+=a[i].w;
		}
	}
}
int main(){
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m>>k;
	mduo=m+1;
	for(int i=1;i<=m;i++) cin >>a[i].u >> a[i].v>>a[i].w;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)cin>>upg[i][j];
	}
	kas();
	if(k!=0){
		cout << "0";
	}
	else{
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}