#include<bits/stdc++.h>
using namespace std;
long long n,m,k,f[10005],cnt,ans;
struct ed{long long u,v,w;
}e[100005];
bool cmp(ed a,ed b){
	return a.w<b.w;
}
long long fd(long long x){return (f[x]==x)?x:(f[x]=fd(f[x]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)f[i]=i;
	for(long long i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(long long i=1;i<=m;i++){
		if(fd(e[i].u)==fd(e[i].v))continue;
		f[fd(e[i].u)]=fd(e[i].v);
		ans+=e[i].w,cnt++;
		if(cnt==n-1){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
