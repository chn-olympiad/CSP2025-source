#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;

struct P{
	long long u,v,w;
	bool operator<(const P a)const{
		return w<a.w;
	}
};
vector<P> e[N];
int n,m,k,cnt;
priority_queue<P,vector<P> , greater<> > q ;
int fa[N],c[N],a[N][N];

int find(int x){
	return fa[x] = (fa[x]==x) ? x : find(fa[x]); 
}
void unionn(int u,int v){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
	return ;
}
long long ans = 0;
int main(){
	freopen("road3.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i =1 ;i<=m;i++){
		int u ,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
		
	}	
	for(int i =1 ;i<=n+k;i++)fa[i]=i;
	if(k==0){
		
		while(cnt<n-1){
			P cur = q.top();
			q.pop();
			int u=cur.u,v=cur.v,w=cur.w;
			if(find(u)==find(v))continue;
			unionn(u,v);
			cnt++;
			ans+=w;
			
		}
		cout<<ans<<'\n';
		return 0;	
	}
	else {
		int flag = 1;
		for(int i =1;i<=k;i++){
			cin>>c[i];
			if(c[i]==0)flag=0;
			for(int j =1 ;j<=n;j++){
				cin>>a[i][j];
				if(a[i][j]==0)flag=0;	
				if(c[i]==0){
					q.push({i+n,j,a[i][j]});
				}
			}
			
		}
		if(flag){
			cout<<0<<'\n';
			return 0;
			
		}
		else {
			while(cnt<n-1){
				P cur = q.top();
				q.pop();
				int u=cur.u,v=cur.v,w=cur.w;
				if(find(u)==find(v))continue;
				unionn(u,v);
				cnt++;
				ans+=w;
			}
			cout<<ans<<'\n';
			return 0;
		}
	}
} 
