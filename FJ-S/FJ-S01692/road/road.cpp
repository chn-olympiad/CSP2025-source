#include<bits/stdc++.h>
using namespace std;
struct sh{
	int s,w;
}a[10012][10012];
int b[10005];
int c[11][10005],p[11],n,o,u;
bool bo[10005],bol[101];
priority_queue <pair < int,int> > q;
pair<int,int> e,ea;
void djk(){
	while(o<n){
		e=q.top();
		q.pop();
		
		if(bo[e.second]==0){
			//cout<<e.first<<" "<<e.second<<endl;
			bo[e.second]=1;
			for(int i=1;i<=b[e.second];i++){
				ea.first=-a[e.second][i].s;
				ea.second=a[e.second][i].w;
				q.push(ea);
			}
			u-=e.first;
			if(e.second<=n){
				o++;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,k,x,y,s;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>s;
		b[x]++;
		b[y]++;
		a[x][b[x]].s=s;
		a[x][b[x]].w=y;
		a[y][b[y]].s=s;
		a[y][b[y]].w=x;
	}
	for(int i=1;i<=k;i++){
		cin>>x;
		b[n+i]=n;
		for(int j=1;j<=n;j++){
			cin>>a[n+i][j].s;
			a[n+i][j].w=j;
		}b[i]++;
		a[i][b[i]].s=x;
		a[i][b[i]].w=n+i;
	}
	ea.first=0;
	ea.second=1;
	q.push(ea);
	djk();
	cout<<u;

	return 0;
}
