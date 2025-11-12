/*
最小生成树 
*/
#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
vector<long long> g[1005],w[1005];
long long c[1005];
long long p[1005];
struct aaa{
	long long u,v,k;
}e[1005];
long long fint(long long x){
	if(p[x]==x)return x;
	else return p[x]=fint(p[x]);
}
bool cmp(aaa x,aaa y){
	return x.k<y.k;
}
void kkk(){
    for(long long i=1;i<=n+k;i++){
        p[i]=i;
    }
    long long ans=0,kk=0;
	sort(e+1,e+1+m,cmp);
    long long s=n;
	for(long long i=1;i<=m;i++){
		long long ue=fint(e[i].u),ve=fint(e[i].v);
		if(ue!=ve){
			p[ue]=ve;
			ans+=e[i].k;
			kk++;
		} 
		if(kk==n-1){
			break;
		}
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,k;
		cin>>u>>v>>k;
		e[i].u=u;
		e[i].v=v;
		e[i].k=k;
		g[u].push_back(v);
		g[v].push_back(u);
		w[u].push_back(k);
		w[v].push_back(k);
	}
	for(long long s=1;s<=k;s++){
		cin>>c[s];
		for(long long i=1;i<=n;i++){
			long long ss;
			cin>>ss;
			g[n+s].push_back(i);
			g[i].push_back(n+s);
			w[n+s].push_back(ss);
			w[i].push_back(ss);
			m++;
			e[m].u=i;
			e[m].v=n+s;
			e[m].u=ss;
		}
	}
	kkk();
	return 0;
}
/*
5 7 0
1 2 7
1 5 2
1 4 7
2 3 1
3 4 10
5 2 1
3 4 1

*/
