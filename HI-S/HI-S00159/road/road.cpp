#include<bits/stdc++.h>
using namespace std;
struct NODE {
	int y,c;
};
vector<NODE>v[10001];
int n,m,k,sum;
int qq=1;
queue<int>q;
bool b[10001];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int x,y,c;
		cin>>x>>y>>c;
		NODE p,o;
		p.y=y,o.y=x;
		p.c=o.c=c;
		v[x].push_back(p);
		v[y].push_back(o);
	}
	for(int i=1; i<=k; i++) {
		int l;
		cin>>l;
		for(int j=1; j<=n; j++) {
			cin>>l;
		}
	}
	q.push(1);
	b[1]=1;
	while(qq<n) {
		int mi=123456789,w=0;
		int si=q.size();
		for(int i=0; i<si; i++) {
			bool f=true;
			for(int j=0; j<v[q.front()].size(); j++) {
				if(b[v[q.front()][j].y]) {
					continue;
				}
				f=false;
				if(mi>v[q.front()][j].c) {
					mi=v[q.front()][j].c;
					w=v[q.front()][j].y;
				}
			}
			if(f)q.pop();
			q.push(q.front());
			q.pop();
		}
		sum+=mi;
		q.push(w);
		b[w]=1;
		qq++;
	}
	cout<<sum;

	return 0;
}

