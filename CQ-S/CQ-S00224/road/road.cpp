#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k,tot;
int x[M],y[M],cnt[M],val[15],head[M],dis[N];
int a[15][N];
bool flag[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
struct node{
	int x,y,val;
}nex[M<<1];
void add(int x,int y,int val){
	tot++;
	nex[tot].x=y;
	nex[tot].y=head[x];
	nex[tot].val=val;
	head[x]=tot;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>x[i]>>y[i]>>cnt[i];
	for(int i=1;i<=k;i++){
		cin>>val[i]; 
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k==0){
		for(int i=1;i<=n;i++)
			add(x[i],y[i],cnt[i]),add(y[i],x[i],cnt[i]);
		memset(dis,0x3f,sizeof dis);
		dis[1]=0;
		q.push(make_pair(0,1));
		while(!q.empty()){
			int y=q.top().first,x=q.top().second;
			q.pop();
			if(flag[x])
				continue;
			flag[x]=true;
			for(int i=head[x];i;i=nex[i].y){
				int w=nex[i].x;
				if(dis[w]>dis[x]+nex[i].val){
					dis[w]=dis[x]+nex[i].val;
					q.push(make_pair(dis[w],w));
				}
			}
		}
		int ma=0;
		for(int i=1;i<=n;i++)
			ma=max(ma,dis[i]);
		cout<<ma;
	}
	else
		cout<<0;
	return 0;
}
