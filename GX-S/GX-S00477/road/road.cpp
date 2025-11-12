#include<bits/stdc++.h>
using namespace std;
const long long N = 1e6+5;
long long n,m,k;
long long ans = LLONG_MAX,cnt = 0,num[N];
struct A{
	long long u,v,w;
}road[N];
bool f[N];
bool check(){
	int e = num[1],c = num[1];
	for(int i=1;i <= n*n;i++){
		if(num[e] == c)return true;
		else if(num[e] == 0)return false;
		e = num[e];
	}
	return false;
}
void dfs(){
	if(check()){
		if(cnt < ans)ans = cnt;
		return;
	}
	for(int i=1;i<=m;i++){
		if(f[i] == 0){
			num[i] = road[i].v;
			cnt += road[i].w;
			f[road[i].u] = 1;
			dfs();
			cnt -= road[i].w;
			f[road[i].u] = 0;
		}
	}
}
bool cmp(A a,A b){
	if(a.u < b.u){
		if(a.w <= b.w)return true;
		else return false;
	}
	else return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
	}
	int a,b,c,d;
	for(int i=1;i<=k;i++){
		cin>>a>>b>>c>>d;
	}
	sort(road,road+m,cmp);
//	for(int i=1;i<=m;i++){
//		cout<<road[i].u<<" "<<road[i].v<<" "<<road[i].w<<'\n';
//	}
	if(k == 0){
		dfs();
		cout<<ans<<endl;
		return 0;
	}

	return 0;
}
