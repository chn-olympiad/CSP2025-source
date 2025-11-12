#include <bits/stdc++.h> 
using namespace std;
int f[10005];
int n,m,k,cnt=1;
struct E{
	int u,v,w;
};
bool cmp(E x,E y){
	return x.w<y.w; 
}
int find(int x){
	return f[x];
}
bool untie(int x,int y){
	int rx=find(x),ry=find(y);
	if(rx==ry) return 0;
	else{
		f[rx]=ry; 
		return 1;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	long long sum=0;
	cin >>n >>m >>k;
	vector<E> g(m);
	for(int i=0;i<m;i++) cin >>g[i].u >>g[i].v >>g[i].w;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(g.begin(),g.end(),cmp);
    for(E i : g){
    	if(untie(i.u,i.v)){
    		sum+=i.w;
    		if(++cnt==n) break;
		}
	}
	cout <<sum;
}
