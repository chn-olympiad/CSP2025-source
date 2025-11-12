#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10010,M=1e6+10;
struct node{
	int x,y;
	ll z;
}a[M*2];
ll c[15];
int fa[N+10];
bool cmp(node a,node b){
	return a.z<b.z;
}
int findfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=findfa(fa[x]);
}
void solve(int n,int m,int k){
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int fx=findfa(a[i].x),fy=findfa(a[i].y);
		if(fx!=fy){
			ans+=a[i].z;
			cnt++;
			fa[fx]=fy;
			if(cnt==n-1)break;
		}
	}
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].z);
	}
	if(k==0){
		solve(n,m,k);
		return 0;
	}
	cout<<0;
	return 0;
}
