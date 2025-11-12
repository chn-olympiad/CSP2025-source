#include<bits/stdc++.h>

using namespace std;

const int N=1e4+10;

int n,m,k,c[N];
int a[12][N],fa[N],tot;

struct edge{
	int u,v,w;
	bool operator<(const edge&x) const 
      { return x.w < w; }
}t[N];

int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}

void Kruscal(){
	priority_queue<edge>q;
	for(int i=1;i<=m;i++){
		q.push(t[i]);
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	while(!q.empty()){
		edge t=q.top();q.pop();
		int u=t.u,v=t.v,w=t.w;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			tot+=w;
			//cout<<tot<<endl;
		}
	}
	cout<<tot;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans%998244353<<endl;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
