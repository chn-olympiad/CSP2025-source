#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII> > q;
int n,m,k,idx;
int w[N],ne[N],h[N],e[N],f[N],c[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(h,-1,sizeof h);
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[idx]=y;
		w[idx]=z;
		ne[idx]=h[x];
		h[x]=idx++;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w[idx];
			ne[idx]=h[j];
			h[j]=idx++;
		}
	}
	f[1]=0;
	q.push({0,1});
	while(!q.empty()){
		PII p=q.top();
		q.pop();
		int v=p.second;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(ne[v]!=-1) f[i]=min(f[i],f[v]+w[v]);
			}
			if(f[i]>f[v]+w[v]) q.push({i,j});
		}
	}
	cout<<f[n];
	return 0;
}
