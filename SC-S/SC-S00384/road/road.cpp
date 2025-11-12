#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,num,tmp[N],f[N],c[N],ans;
bool b[N];
struct road{
	int u,v,w,m;
	friend bool operator <(road a,road b){
		return a.w>b.w;
	}
}rem[N];
vector<road> mp[N];
priority_queue<road> krus;
void add(int u,int v,int w,int m){
	road a;
	a.u=u,a.v=v,a.w=w,a.m=m;	
	krus.push(a);
}
int find(int u){
	if(u==f[u])return u;
	return f[u]=find(f[u]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	num=n;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1,u,v,w;i<=n;i++){
		cin>>u>>v>>w;
		add(u,v,w,m);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int u=1;u<=n;u++){
			cin>>tmp[u];
			for(int v=1;v<u;v++)
				add(u,v,tmp[u]+tmp[v],i);
		}
	}
	b[0]=true;
	while(num>1){
		road a=krus.top();
		krus.pop();
		if(find(a.u)==find(a.v))continue;
		if(a.m<0){
			a.m=-a.m;
			b[a.m]=true;
			f[find(a.u)]=find(a.v);
			ans+=a.w;
			num--;
			continue;
		}
		if(!b[a.m]){
			if(a.w+c[a.m]<=krus.top().w){
				b[a.m]=true;
				f[find(a.u)]=find(a.v);
				ans+=a.w+c[a.m];
				num--;	
			}
			else{
				a.w+=c[a.m];
				a.m=-a.m;
				krus.push(a);
			}
		}
		else{
			f[find(a.u)]=find(a.v);
			ans+=a.w;
			num--;
		}
	}
	cout<<ans;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
