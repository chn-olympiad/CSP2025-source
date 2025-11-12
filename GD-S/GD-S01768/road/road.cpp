#include<bits/stdc++.h>
using namespace std;
const int gm=4000005;
int n,m,k,tc=0;
int c[15],a[15][10005],p[10050],ans=1e10;
int cnt=0;
struct edge{
	int u,v,len;
}t[gm];
bool cmp(edge x,edge y){
	return x.len<y.len;
}
void add(int u,int v,int w){
	t[++cnt].u=u;
	t[cnt].v=v;
	t[cnt].len=w;
}
int fad(int x){
	if(p[x]==0){
		return x; 
	}
	p[x]=fad(p[x]);
	return p[x];
}
void hb(int x,int y){
	int fx=fad(x),fy=fad(y);
	if(fx!=fy)p[fx]=fy;
}
int check(int x,int y){
	int fx=fad(x),fy=fad(y);
	if(fx==fy)return 1;
	else return 0;
}
//priority_queue<edge> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	int fg=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)fg=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)fg=0;
		}
	}
	if(k==0){
		ans=0;
		sort(t+1,t+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			if(check(t[i].u,t[i].v)==1){
				continue;
			}
			else{
				hb(t[i].u,t[i].v);
				ans+=t[i].len;
				cout<<ans<<'\n';
			}
		}
		cout<<ans;
		return 0;
	}
	if(fg==1&&k!=0){
		cout<<0;
		return 0;
	}
	for(int zt=0;zt<(1<<k);zt++){
		int tcnt=cnt,tans=0,tc=0;
		for(int j=0;j<k;j++){
			if(zt&(1<<j)){
				tans+=c[j+1];
				for(int i=1;i<=n;i++){
				for(int k=1;k<=n;k++){
					add(i,k,a[j+1][i]+a[j+1][k]);
					tc++;	
				}					
				}
			}
		}
		sort(t+1,t+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			if(check(t[i].u,t[i].v)==1){
				continue;
			}
			else{
				hb(t[i].u,t[i].v);
				tans+=t[i].len;
			}
		}
		ans=min(ans,tans);
		for(int i=tcnt+1;i<=cnt;i++){
			t[i].u=t[i].v=t[i].len=0;
		}
		for(int i=1;i<=n;i++)p[i]=0;
		cnt=tcnt;
		if(tc>=10000000){
			break;
		}
	}
	cout<<ans<<'\n';
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
