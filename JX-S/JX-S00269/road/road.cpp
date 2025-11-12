#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+5;
struct node{
	int u,v;
};
struct edge{
	int u,v,val;
	friend bool operator < (edge x,edge y){
		return x.val>y.val;
	}
};
int n,m,k,c[15],a[N],w[N][N],fa[N],ans;
priority_queue<edge> q;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool join(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return 0;
	fa[fx]=fy;
	return 1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int fr,to,val;
		cin>>fr>>to>>val;
		if(fr>to) swap(fr,to);
		if(val==0) val=-1;
		if(w[fr][to]==0) w[fr][to]=val;
		else w[fr][to]=min(w[fr][to],val);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[j];
		//for(int j=1;j<=n;j++)
			//cout<<a[j]<<"\n";
		for(int j=1;j<=n;j++){
			for(int z=j+1;z<=n;z++){
				int op=c[i]+a[j]+a[z];
				if(op==0) op=-1;
				if(w[j][z]==0) w[j][z]=op;
				else w[j][z]=min(w[j][z],op);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int op=w[i][j];
			if(op==0) op=-1;
			if(w[i][j]!=0) q.push((edge){i,j,op});
			//cout<<w[i][j]<<" ";
		}
		//cout<<"\n";
	}
	//cout<<114;
	int num=n;
	//cout<<q.size();
	while(num&&!q.empty()){
		//cout<<1<<"\n";
		edge now=q.top();
		q.pop();
		int x=now.u,y=now.v,op=now.val;
		//cout<<x<<" "<<y<<" "<<op<<"\n";
		if(join(x,y)){
			//<<x<<" "<<y<<"\n";
			num--;
			ans+=op;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
