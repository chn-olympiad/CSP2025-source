#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXM=4e6+2;
const int MAXN=1e4+3;
struct node{
	int a,b,val;
}r[MAXM];
int cnt,ba[MAXN];
int fa[MAXN];
int findf(int x){
	if(fa[x]==x) return x;
	return fa[x]=findf(fa[x]);
}
bool cmp(node a,node b){
	return a.val<b.val;
}
int n,m,k;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int a,b,z;
		scanf("%lld%lld%lld",&a,&b,&z);
		cnt++;
		r[cnt].a=a;
		r[cnt].b=b;
		r[cnt].val=z;
	}
	for(int i=1;i<=k;i++){
		int base;
		scanf("%lld",&base);
		for(int j=1;j<=n;j++){
			scanf("%lld",&ba[j]);
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				cnt++;
				r[cnt].a=j;
				r[cnt].b=k;
				r[cnt].val=ba[j]+ba[k]+base;
			}
		}
	}
	sort(r+1,r+1+cnt,cmp);
	int sum=1,h=1,ans=0;
	while(sum<n){
		int a=r[h].a,b=r[h].b,z=r[h].val;
		if(findf(a)==findf(b)){
			h++;
			continue;
		}
		else{
			fa[a]=b;
			ans+=z;
			sum++;
		}
	}
	printf("%lld",ans);
	return 0;
}