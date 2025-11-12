#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e4+20,MAXM=1e6+1e5+10;

struct edge{
	int x,y,w,con;
}e[MAXM];

int n,m,k,elen=0;
int c[20],fa[MAXN];

struct node{
	int x,y,w,con;
	bool operator < (const node &a) const{
		return w+c[con]>a.w+c[a.con];
	}
};

priority_queue<node> q;

bool cmp(edge a,edge b){
	return a.w<b.w;
}

int findfa(int x){
	if (x!=fa[x]) fa[x]=findfa(fa[x]);
	return fa[x];
}

void composed(int x,int y){
	x=findfa(x),y=findfa(y);
	fa[x]=y;
}

long long kruscal(){
	int cnt=0;
	long long res=0l;
	for (int i=1;i<=elen;i++){
		int xfa=findfa(e[i].x),yfa=findfa(e[i].y);
		if (xfa==yfa) continue;
		if (c[e[i].con]){
			q.push({e[i].x,e[i].y,e[i].w,e[i].con});
			continue;
		}
		while (!q.empty()&&q.top().w+c[q.top().con]<e[i].w){
//			cout <<'x';
			if (!c[q.top().con]) cnt++;
			res+=1ll*q.top().w+c[q.top().con];
			c[q.top().con]=0;
			composed(q.top().x,q.top().y);
			q.pop();
			if (cnt==n-1) return res;
		}
		composed(e[i].x,e[i].y);
		res+=1ll*e[i].w,cnt++;
		if (cnt==n-1) return res;
	}
	while (!q.empty()){
		if (!c[q.top().con]) cnt++;
		res+=1ll*q.top().w+c[q.top().con];
		c[q.top().con]=0;
		composed(q.top().x,q.top().y);
		q.pop();
		if (cnt==n-1) return res;
	}
	return -1l;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n >>m >>k;
	for (int i=1;i<=m;i++){
		elen++;
		cin >>e[elen].x >>e[elen].y >>e[elen].w;
		e[elen].con=0;
	}
	for (int i=1;i<=k;i++){
		cin >>c[i];
		for (int j=1;j<=n;j++){
			elen++;
			cin >>e[elen].w;
			e[elen].x=j,e[elen].y=n+i,e[elen].con=i;
		}
	}
	for (int i=1;i<=n+k;i++)
		fa[i]=i;
	sort(e+1,e+elen+1,cmp);
	cout <<kruscal() <<'\n';
	return 0; 
}
