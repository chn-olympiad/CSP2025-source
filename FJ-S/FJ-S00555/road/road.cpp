#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+4;
int n,m,k,cnt,ans;
bool che;
int a[maxn][maxn],o[maxn];
struct hhh{
	int u,v,w;
}r[maxn];
bool cmp(hhh x,hhh y){
	return x.w>y.w;
}
void hh(int x){
	if(cnt==n){
		che=true;
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[x][i]==1 && o[i]==0){
			o[i]=1;
			cnt++;
			hh(i);
		}
	}
}
bool check(){
	memset(o,0,sizeof o);
	che=false;
	o[1]=1;
	cnt=1;
	hh(1);
	if(che) return true;
	else return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
		a[r[i].u][r[i].v]=1;
		a[r[i].v][r[i].u]=1;
		ans+=r[i].w;
	}			
	sort(r+1,r+1+m,cmp);
	for(int i=1;i<=m;i++){
		a[r[i].u][r[i].v]=0;
		a[r[i].v][r[i].u]=0;
		if(check()){
			ans-=r[i].w;
		}
		else{
			a[r[i].u][r[i].v]=1;
			a[r[i].v][r[i].u]=1;
		}
	}
	cout<<ans;
	return 0;
}
