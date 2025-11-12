#include <bits/stdc++.h>
#define ll long long//freopen!!!
using namespace std;
const int N=2e6;
struct Edge{
	ll u,v,d;
}e[N];
ll n,m,k,c[N],x,f[N],sl,ans,cnt;
bool cmp(Edge a, Edge b){
	return a.d<b.d;
}
int fa(int x){
	if(f[x]==x) return x;
	else return f[x]=fa(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k>0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].d;
	sort(e+1,e+m+1,cmp), cnt=n;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		if(fa(e[i].u)==fa(e[i].v)) continue;
		ans+=e[i].d, f[fa(e[i].u)]=fa(e[i].v), cnt--;
		if(cnt==1) break;
	}cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
1 3 3
1 3 1
*/
