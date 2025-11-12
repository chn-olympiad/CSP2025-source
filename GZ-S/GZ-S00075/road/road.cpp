/*GZ-S00075 毕节梁才学校 卢麟一*/
#include<bits/stdc++.h>
using namespace std;
int x,n,m,ans,k,h[100010],idx,to[100010],nt[100010],w[100010],c,u,d[100010];
bool v[100010];
typedef pair<int,int> PII;
priority_queue<PII, vector<PII>, greater<PII> > q;
void add(int x,int y,int z) {
	to[idx]=y;
	nt[idx]=h[x];
	h[x]=idx;
	w[idx]=z;
	idx++;
}
void diji(int u) {
	q.push((PII) {
		0,u
	});
	d[u]=0;
	while(!q.empty()) {
		PII top=q.top();
		q.pop();
		int t=top.second;
		if(!v[t]) {
			v[t]=true;
			for(int i=h[t]; i!=1; i=nt[i]) {
				int j=to[i];
				if(d[t]+w[i]<d[j]) {
					d[j]=w[i]+d[t];
					q.push((PII) {
						d[j],j
					});
				}
			}
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(d,0x3f,sizeof(d));
	for(int i=1; i<=m; i++) {
		int i1,i2,i3;
		scanf("%d%d%d",&i1,&i2,&i3);
		add(i1,i2,i3);
	}
	for(int i=m+1; i<=m+k; i++) {
		int i1;
		scanf("%d",&i1);
		for(int j=1; j<=m; j++) {
			int i2;
			scanf("%d",&i2);
			add(i,j,i2);
		}
	}
	diji(1);
	for(int i=1;i<=n;i++) ans+=d[i];
	cout<<ans;
	return 0;
}
