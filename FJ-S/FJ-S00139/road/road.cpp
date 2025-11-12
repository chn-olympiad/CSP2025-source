#include<bits/stdc++.h>
using namespace std;
const int N=4e6+10;
struct edge{
	int nx,to,dis;
}e[N];
int n,m,k;
int cnt,f[N],d[N],flag;
long long ans;
bool cmp(edge x,edge y){
	return x.dis<y.dis;
}
int ff(int x){
	if(f[x]!=x) f[x]=ff(f[x]);
	return f[x];
}
bool v[N];
int main(){
	freopen("road.in","r",stdin);
//	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m>>k;
	for(int i=1;i<=n+2*k;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].nx>>e[i].to>>e[i].dis;
	flag=m+1;
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		e[flag].nx=n+i,e[flag].to=n+i+k,e[flag].dis=c;
		flag++;
		for(int j=1;j<=n;j++){
			int C;
			cin>>C;
			e[flag].nx=j,e[flag].to=n+i,e[flag].dis=C;
			flag++;
			e[flag].nx=i+n+k,e[flag].to=j,e[flag].dis=C;
			flag++;
		}
	}
	sort(e+1,e+flag-1,cmp);
	for(int i=1;i<flag;i++){
		if(cnt==n+2*k-1) break;
		int x=ff(e[i].nx),y=ff(e[i].to);
		if(x!=y){
			cnt++;
			v[e[i].nx]=1;
			ans+=e[i].dis;
			f[x]=y;
		}
	}
	cout<<ans<<endl;
	return 0;
}
