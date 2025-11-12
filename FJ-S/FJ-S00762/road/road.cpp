#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=1e9;
int n,m,k;
int fa[10500];
ll ans=0,a[10500],fn[10500];
struct rd{
	ll fs=0;
	int f,t;
}q[3000500];
/*struct edge{
	ll w;
	
};*/

vector<ll> p[10500];
bool cmp(rd x,rd y){
	return x.fs<y.fs;
}

int find(int x){
	if(fa[x]==x){
		return x;
	}else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
void join(int x,int y){
	fa[find(x)]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int s,e;
		ll rmb; 
		cin>>s>>e>>rmb;
		q[i].f=s,q[i].t=e,q[i].fs=rmb;
	}
	if(k==0){
		sort(q+1,q+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(find(q[i].f) != find(q[i].t)){
				join(q[i].f,q[i].t);
				ans+=q[i].fs;
			}
		}
		cout<<ans;
		return 0;
	}
	int cnt=0;
	for(int j=1;j<n;j++){
		for(int l=j+1;l<=n;l++){
			p[j].push_back(inf);
		}
	}
	
	for(int i=1;i<=k;i++){
		ll fe,nm;
		cin>>fe;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<n;j++){
			for(int l=j+1;l<=n;l++){
				p[j][l-j-1]=min(p[j][l-j-1],a[j]+a[l]);
			}
		}
	}
	for(int j=1;j<n;j++){
		for(int l=j+1;l<=n;l++){
			q[m+1+cnt].fs=p[j][l-j-1];
			q[m+1+cnt].f=j;
			q[m+1+cnt].t=l;
			cnt++;
		}
	}
	sort(q+1,q+1+m+cnt,cmp);
	for(int i=1;i<=m+cnt;i++){
		if(find(q[i].f) != find(q[i].t)){
			join(q[i].f,q[i].t);
			ans+=q[i].fs;
		}
	}
	cout<<ans;

	return 0;
} 
