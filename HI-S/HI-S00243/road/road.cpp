#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
struct node{
	int v,u,l;
}p[1000002];
bool cmp(node aa,node bb){
	return aa.l<bb.l;
}
int fh[10002];
int fa(int xx){
	return (fh[xx]==xx)?xx:fh[xx] = fa(fh[xx]);
}
int n,m,k;
void solve(){
	ll aans = 0;
	fr(i,1,m)cin>>p[i].v>>p[i].u>>p[i].l;
	sort(p+1,p+m+1,cmp);
	fr(i,1,n)fh[i] = i;
	for(int i=1;i<=m;i++){
		int fv = fa(p[i].v),fu = fa(p[i].u); 
		if(fv==fu)continue;
		aans+=p[i].l;
		fh[fv] = fu;
	}
	cout<<aans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	if(k==0)solve();
	cout<<0;
	
	return 0;
}

