//GZ-S00087 贵阳市华师一学校 吴松阳
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4+15,maxm=1e6+10;
struct road {
	int fr,to,w;
};
vector<road> p1;
int d[maxn][maxn];
int n,m,k;
int c[maxn];
int u,v,x;

bool cmp(road a,road b) {
	return a.w<b.w;
}

int main() {
  	freopen("road.in", "r", stdin);
  	freopen("road.out", "w", stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&u,&v,&x);
		road tmp;
		tmp.fr=u,tmp.to=v,tmp.w=x;
		p1.push_back(tmp);
		swap(tmp.fr,tmp.to);
		p1.push_back(tmp);
	}
	for(int i=1; i<=k; i++) {
		scanf("%d",&c[i]);
		for(int j=1; j<=n; j++) {
			scanf("%d",&x);
			road tmp;
			tmp.fr=n+i,tmp.to=j,tmp.w=x;
			p1.push_back(tmp);
			swap(tmp.fr,tmp.to);
			p1.push_back(tmp);
		}
	}
	road p[p1.size()];
	for(int i=0; i<p1.size(); i++) {
		p[i]=p1[i];
	}
	sort(p,p+p1.size(),cmp);
	ll ans=0;
	for(int i=0; i<=n+k; i++)
		for(int j=0; j<=n+k;j++) d[i][j]=999999999;
	for(int i=0; i<p1.size(); i++) {
		if(d[p[i].fr][p[i].to]>p[i].w) {
			d[p[i].fr][p[i].to]=p[i].w;
			ans+=p[i].w;
			for(int j=1; j<=n; j++) {
				if(d[p[i].fr][j]==999999999) continue;
				if(d[j][p[i].to]>p[i].w+d[p[i].fr][j]) {
					ans-=d[j][p[i].to]!=999999999 ? d[j][p[i].to] : 0;
				}
				d[j][p[i].to]=min(d[j][p[i].to],p[i].fr+d[p[i].fr][j]);
			}
		}
	}
	cout<<ans/2;
	return 0;
}

