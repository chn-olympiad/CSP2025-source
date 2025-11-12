#include<bits/stdc++.h>
using namespace std;
struct e{
	long long u,v,w;
}ed[1300005];
long long fa[12337],n,m,k,ans,num,cur=0;
bool cmp(e a,e b){
	return a.w<b.w;
}
long long unifind(long long x){
	if(fa[x]==x)return x;
	else return fa[x]=unifind(fa[x]);
}
void merge(long long x,long long y){
	fa[unifind(x)]=unifind(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> ed[i].u >> ed[i].v >> ed[i].w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin >> c;
		if(c==0){
			for(int j=1;j<=n;j++){
				int x;
				cin >> x;
				ed[++m].u=n+i;
				ed[m].v=j;
				ed[m].w=x;
			}
		}
	}
	sort(ed+1,ed+1+m,cmp);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	while(num<n+k-1){
		cur++;
		if(unifind(ed[cur].u)!=unifind(ed[cur].v)){
			num++;
			ans+=ed[cur].w;
			merge(ed[cur].u,ed[cur].v);
		}
	}
	cout << ans << endl;
	return 0;
}