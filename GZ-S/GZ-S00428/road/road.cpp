//GZ-S00428 毕节梁才学校 赵纤茹
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int p[1000+10];
bool v[20][1000+10];
int c[20];
int find(int x) {
	if(p[x]!=x) {
		p[x]=find(p[x]);
	}
	return p[x];
}
struct XIU {
	int u,v,w,id;
	bool operator<(const XIU&B)const {
		return w<B.w;
	}
	bool operator>(const XIU&B)const {
		return w>B.w;
	}
};
priority_queue<XIU,vector<XIU>,greater<XIU> > q;
int main() {
	freopen("road3.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		q.push((XIU) {u,v,w,0});
	}
	for(int i=1; i<=k; i++) {
		scanf("%d",&c[i]);
		for(int j=1; j<=n; j++) {
			int x;
			scanf("%d",&x);
			q.push((XIU){i,j,c[i],x});
		}
	}
	int ans=0,cnt=n;
	for(int i=1; i<=n; i++) p[i]=i;
	while(!(q.empty())) {
		XIU x=q.top();
		if(x.id==0) {
			int gx=find(x.v);
			int gy=find(x.u);
			if(gx!=gy) {
				p[gx]=gy;
				cnt--;
				ans+=x.w;
			}
			q.pop();
		} else {
			if(!v[x.u][x.v]) {
				q.pop();
				q.push((XIU) {x.u,x.v,x.w+c[x.u],x.id});
				v[x.u][x.v]=true;
			} else {
				int gx=find(x.v);
				int gy=find(x.u);
				if(gx!=gy) {
					p[gx]=gy;
					cnt--;
					ans+=x.w;
				}
				q.pop();
			}
		}
		if(cnt==0) break;
	}
	printf("%d",ans);
	return 0;
}
