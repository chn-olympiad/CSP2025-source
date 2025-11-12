#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0;
int f[10005],r[10005];
struct A{
	int u,v;
	long long w;
};
vector<A> a;
bool cmp(A x, A y){
	return x.w < y.w;
}
int find(int x){
	if(f[x] == x) return x;
	else return f[x] = find(f[x]);
}
void dijs(){
	int l = a.size();
	for(int i=1; i <= n; i++){
		f[i] = i;
		r[i] = 1;
	}
	for(int i=0; i < l; i++){
		int x = a[i].u, y = a[i].v;
		int xx=find(x), yy=find(y);
		if(xx == yy) continue;
		f[xx] = y;
		r[y] += r[xx];
		ans += a[i].w;
		for(int j=1; j <= n; j++){
			if(r[j] == n) return;
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	A x;
	for(int i=1; i <= m; i++){
		cin>>x.u>>x.v>>x.w;
		a.push_back(x); 
	}
	for(int i=1; i <= k; i++){
		long long e[n+5];
		for(int j=0; j <= n; j++) cin>>e[j];
		for(int j=1; j <= n; j++){
			x.u = i;
			x.v = j;
			x.w = e[0] + e[j];
			if(i != j) x.w += e[i];
			a.push_back(x);
		}
	}
	sort(a.begin(),a.end(),cmp);
	dijs();
	cout<<ans;
	return 0;
}
