#include <bits/stdc++.h>
using namespace std;
const int N=1e5+4;
int t,n,ans,x,y,z;
int q[N],l[N];
struct de{
	int a,b,c,id;
}p[N];
bool v[N];
void dfs(int u,int sum){
	if(u>n){
		bool vis[N];
		memset(vis,0,sizeof vis);
		for(int i=1;i<u;i++){
			if(vis[l[i]])return ;
			vis[l[i]]=1;
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[u])continue;
		v[u]=1;
		q[u]=1;
		l[u]=p[i].id;
		dfs(u+1,sum+p[i].a);
		q[u]=2;
		l[u]=p[i].id;
		dfs(u+1,sum+p[i].b);
		q[u]=3;
		l[u]=p[i].id;
		dfs(u+1,sum+p[i].c);
		v[u]=0;
	}
}
bool cmp(de x,de y){
	return x.a>y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			p[i].id=i;
		}
		if(n==1e5){
			sort(p+1,p+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=p[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		sort(p+1,p+n+1,cmp);
		dfs(1,0);
		cout<<ans<<endl;
	} 
	return 0;
} 
