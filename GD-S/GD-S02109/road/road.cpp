//road
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Road{
	int a,b;
	ll k;
	bool operator<(const Road a)const{
		return k<a.k;
	}
}a;
vector<Road> v;
int n,m,e,q,sum;
ll cnt,ans;
int f[10020];
ll c[10020],d[13][10020];
int find(int x){
	return x==f[x]?x:(f[x]=find(f[x]));
}
bool merge(int x,int y){
	x=find(x),y=find(y);
	f[x]=y;
	return x!=y; 
}
void upd(){
	for(int i=1;i<=n+q;i++) f[i]=i;
	sort(v.begin(),v.end());
	vector<Road> r;
	for(Road x:v){
		if(r.size()==n+q-1) break;
		if(merge(x.a,x.b)) r.push_back(x);
	}
	v=r;
}
void dfs(int k){
	vector<Road> t=v;
	if(k>e){
		upd();
		cnt=0;
		for(auto x:v) cnt+=x.k;
		ans=min(ans,sum+cnt);
	}else{
		dfs(k+1);
		q++,sum+=c[k];
		for(int i=1;i<=n;i++){
			a.a=i,a.b=n+q,a.k=d[k][i];
			v.push_back(a);
		}
		upd();
		dfs(k+1);
		q--,sum-=c[k];
	}
	v=t;
}
int read(){
	char c;
	while(!isdigit(c=getchar()));
	int k=c-'0';
	while(isdigit(c=getchar())) k=k*10+c-'0';
	return k;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),e=read();
	for(int i=1;i<=n;i++) f[i]=i;
	while(m--){
		a.a=read(),a.b=read(),a.k=read();
		v.push_back(a);
	}
	for(int i=1;i<=e;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) d[i][j]=read();
	}
	ans=1ll<<62;
	upd(),dfs(1);
	printf("%lld",ans);
	return 0;
}
