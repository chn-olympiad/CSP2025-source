#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt,ans;
struct node{
	long long v,w,nex;
}a[1000006];
long long head[1000006];
map<int,int>mp;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		long long u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		a[++cnt].v=v;
		a[cnt].w=w;
		a[cnt].nex=head[u];
		head[u]=cnt;
		ans+=w;
	}
	printf("%lld",ans);
	return 0;
}
