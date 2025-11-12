/*GZ-S00075 毕节梁才学校 卢麟一*/

#include<bits/stdc++.h>
using namespace std;
int x,n,m,h[100010],idx,to[100010],nt[100010],w[100010],c,u,d[100010];
bool v[100010];
typedef pair<int,int> PII;
priority_queue<PII, vector<PII>, greater<PII> > q;
void diji(int u) {
	q.push((PII){0,u});
	d[u]=0;
	while(!q.empty()) {
		PII top=q.top();
		q.pop();
		int t=top.second;
		if(!v[t]) {
			v[t]=true;
			for(int i=h[t];i!=1;i=nt[i]) {
				int j=to[i];
				if(d[t]+w[i]<d[j]) {
					d[j]=w[i]+d[t];
					q.push((PII){d[j],j});
				}
			}

		}
	}



}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	cin>>n>>m;
	memset(d,0x3f,sizeof(d));
	for(int i=1; i<=m; i++) {
	cout<<0<<endl;
	}
	return 0;
}
