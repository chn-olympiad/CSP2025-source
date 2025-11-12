#include<bits/stdc++.h>
using namespace std;
struct road{
	long long u,v,w;
}s[10000001];
bool cmp(road a,road b){
	return a.w<b.w;
}
long long n,m,k,f[10001],max_w,l,ans;
int gf(int x){
	if(f[x]==x)
		return x;
	return f[x]=gf(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	l=m;
	for(int i=1;i<=m;++i){
		cin>>s[i].u>>s[i].v>>s[i].w;
		max_w=max(max_w,s[i].w);
		f[i]=i;
	}
	for(int i=1;i<=k;++i){
		long long c,a[10001];
		cin>>c;
		for(int j=1;j<=n;++j)
			cin>>a[j];
		for(int j=1;j<n;++j){
			for(int k=j+1;k<=n;++k){
				if(a[j]+a[k]+c<=max_w)
					s[++l].u=a[j],s[l].v=a[k],s[l].w=a[j]+a[k]+c;
			}
		}
	}
	sort(s+1,s+l+1,cmp);
	for(int i=1;i<=l;++i){
		long long fu=gf(s[i].u),fv=gf(s[i].v);
		if(fu!=fv)
			f[fu]=fv,ans+=s[i].w;
	}
	cout<<ans;
	return 0;
}

