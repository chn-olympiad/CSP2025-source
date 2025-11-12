#include<bits/stdc++.h>
using namespace std;
inline int fr(){
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x*10)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int n,m,k;
struct asd{
	int n,s;
}; 
struct qwe{
	int n,s,a;//
};
vector<asd> g[10005];
queue<qwe> q;
int vis[10005]={0},ans=INT_MAX,a[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=fr();m=fr();k=fr();
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			a[i][j]=fr();
		} 
	}
	q.push({1,1,0});//
	while(!q.empty()){
		qwe u=q.front();
		q.pop();
		if(u.s==n){
			ans=min(ans,u.a);
			continue;
		}
		//cout<<u.n<<" "<<u.s<<" "<<u.a<<endl;
		for(int i=0;i<g[u.n].size();i++){
			asd v=g[u.n][i];
			if(!vis[v.n]){
				int go=INT_MAX;
				for(int i=1;i<=k;i++){
					go=min(go,a[i][u.n]+a[i][v.n]);
				}
				q.push({v.n,u.s+1,u.a+min(v.s,go)});
			}
		}
	}
	cout<<ans;
	return 0;
}

