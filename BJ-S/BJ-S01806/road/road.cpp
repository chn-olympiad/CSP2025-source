#include <bits/stdc++.h>
using namespace std;
struct line{
	int u,v,w;
};
int choose[15],val[15];
int fa[1000035];
line a[1100005];
int n,m,k;
int find(int num) {
	if (num==fa[num]) {
		return num;
	}
	return fa[num]=find(fa[num]);
}
bool cmp(line x,line y) {
	return x.w<y.w;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=1000005;i++) fa[i]=i;
	for (int i=1;i<=m;i++) {
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for (int i=1;i<=k;i++) {
		scanf("%d",&val[i]);
		for (int j=1;j<=n;j++) {
			a[m+i*j].u=j;
			a[m+i*j].v=m+i;
			scanf("%d",&a[m+i*j].w);
		}
	}
	m+=k*n;
	int n1=n;
	sort(a+1,a+m+1,cmp);
	int top=0;
	long long ans=0;
	for (int i=1;i<=m;i++) {
		int subu=a[i].u,subv=a[i].v;
		int nowu=a[i].u,nowv=a[i].v;
		subu=find(subu);subv=find(subv);
		if (subu==subv&&nowv<=m) continue;
		fa[subu]=subv;
		ans+=a[i].w;
		if (nowu<=n1&&nowv<=n1) {
			top++;
		}
		//cout<<nowu<<' '<<nowv<<' '<<top<<'\n';
		if (top+1==n) {
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
