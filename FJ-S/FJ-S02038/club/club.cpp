#include<bits/stdc++.h>
using namespace std;
#define int long long
int d[100005][5];
int ap[100005];
int bp[100005];
int cp;
int gs;
int n;
struct node{
	int a,b,c;
	int be;
	const  operator <(const node&w )const{
		return	 be>w.be;
	}
}l[100005];
int dfs(int aa,int bb,int cc,int xs,int zs){
	if(xs>n){
		return zs;
	}
	int aaa=0,bbb=0,ccc=0;
	if(aa<gs)aaa=dfs(aa+1,bb,cc,xs+1,zs+d[xs][1]);	
	if(bb<gs)bbb=dfs(aa,bb+1,cc,xs+1,zs+d[xs][2]);
	if(cc<gs)ccc=dfs(aa,bb,cc+1,xs+1,zs+d[xs][3]);
	int ma=max(aaa,max(bbb,ccc));
	return ma;
}
void solve(){
	cin>>n;
	gs=n/2;
	for(int i=1;i<=n;i++){
	cin>>d[i][1]>>d[i][2]>>d[i][3];
	}
	cout<<dfs(0,0,0,1,0)<<"\n";
	return ;

}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
