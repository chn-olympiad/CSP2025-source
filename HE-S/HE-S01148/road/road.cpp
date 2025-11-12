#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6; 
int p[N],cnt;
ll ans;
bool flag;
int n,m,k,b[N];
int find(int kk){
	if(p[kk]==kk) return kk;
	p[kk]=find(p[kk]);
}
struct st{
	int x,y,z;
}a[N];
bool cmp(st c,st d){
	return c.z<d.z;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	int len=m; 
	for(int i=1;i<=k;i++){
		flag=1;
		int o;
		scanf("%d",&o);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[++len].z);
			a[len].x=i+n;
			a[len].y=j;
		}
	}
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++){
		int zx=find(p[a[i].x]),zy=find(p[a[i].y]);
		if(zx!=zy){
			if(a[i].x<=n && a[i].y<=n) cnt++;
			p[zx]=zy;
			ans+=a[i].z;
		}
		if(cnt==n-1 && flag) break;
	}
	printf("%lld",ans);
	return 0;
}
