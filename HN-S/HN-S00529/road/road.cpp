#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,c,at,ans=0,d[10010],f[10000010];
struct cd{
	ll u,v,w;
}a[10000010];
ll find(ll x){
	if(f[x]!=x)
		return f[x]=find(f[x]);
	return x;
}
bool cmp(cd x,cd y){
	return x.w<y.w;
}
void kal(){
	for(int i=1;i<=at;i++){
		ll u=find(a[i].u),v=find(a[i].v);
		if(u==v)
			continue;
		//cout<<u<<' '<<v<<' '<<a[i].w<<endl;
		f[v]=u,ans+=a[i].w;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	at=m;
	for(ll i=1;i<=k;i++){
		cin>>c;
		for(ll j=1;j<=n;j++)
			cin>>d[j];
		for(ll j=1;j<n;j++)
			for(ll l=j+1;l<=n;l++)
				a[++at].u=j,a[at].v=l,a[at].w=c+d[j]+d[l];
	}
	sort(a+1,a+at+1,cmp);
	for(ll i=1;i<=at;i++)
		f[i]=i;
	kal();
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
