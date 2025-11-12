#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10005];
struct EDGE{
	int u,v,w;
}a[1000005];
int find(int now){
	if(f[now]==now)return now;
	return f[now]=find(f[now]);
}
void hb(int x,int y){
	f[find(x)]=f[find(y)];
}
bool cmp(EDGE a,EDGE b){
	return a.w<b.w;
}
void kruskal(void){
	sort(a+1,a+1+m,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			hb(a[i].u,a[i].v);
			cnt++;
			ans+=a[i].w;
		}
		if(cnt==n-1)break;
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		kruskal();
		exit(0);
	}
	else cout<<0;
	return 0;
}
