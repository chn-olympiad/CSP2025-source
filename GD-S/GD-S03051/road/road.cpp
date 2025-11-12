#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,a,u,w,i,j,r=LLONG_MAX,f[200000],c[200000];
struct T{ll x,y,z;}t[2000000],s[2000000];
ll find(ll x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=0;i<m;i++)cin>>t[i].x>>t[i].y>>t[i].z;
	sort(t,t+m,[](T a,T b){return a.z<b.z;});
	for(i=1;i<=n;i++)f[i]=i;
	for(i=0;i<m;i++){
		if(find(t[i].x)!=find(t[i].y)){
			s[u++]=t[i];
			f[find(t[i].x)]=find(t[i].y);
		}
	}
	for(i=1;i<=k;i++){
		cin>>c[i];
		for(j=1;j<=n;j++){
			cin>>a;
			s[u++]={n+i,j,a};
		}
	}
	sort(s,s+u,[](T a,T b){return a.z<b.z;});
	for(i=0;i<1<<k;i++){
		w=0;
		for(j=1;j<=k;j++){
			if((i>>(j-1))&1){
				w+=c[j];
				if(w>r)break;
			}
		}
		for(j=1;j<=n+k;j++)f[j]=j;
		for(j=0;j<u;j++){
			if(s[j].x>n&&!((i>>(s[j].x-n-1))&1))continue;
			if(find(s[j].x)!=find(s[j].y)){
				f[find(s[j].x)]=find(s[j].y);
				w+=s[j].z;
				if(w>r)break;
			}
		}
		r=min(r,w);
	}
	return cout<<r,0;
}
