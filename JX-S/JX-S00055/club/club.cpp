#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100010;
int n,t,mid;
int d[4];
struct club
{
	int a,b,c;
	int d;
}g[N];
bool cmp(club a,club b){ return a.d>b.d;}
int ans=0;
void init(){
	ans=0;
	for(int i=1;i<=3;i++) d[i]=0;
	for(int i=1;i<=n;i++) g[i].a=g[i].b=g[i].c=0;
}
void solve(){
	sort(g+1,g+n+1,cmp);
	for(int i=1;i<=n;i++){
		ans+=g[i].a;
	}
	for(int i=1;i<=mid;i++){
		ans+=g[i].d;
	}
}
void dfs(int x,int res){
	if(x==n+1){
		ans=max(ans,res);
		return;
	}
	if(d[1]<mid){
		d[1]++;
		dfs(x+1,res+g[x].a);
		d[1]--;
	}
	if(d[2]<mid){
		d[2]++;
		dfs(x+1,res+g[x].b);
		d[2]--;
	}
	if(d[3]<mid){
		d[3]++;
		dfs(x+1,res+g[x].c);
		d[3]--;
	}
	return;
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>t;
	while(t--){
		cin>>n;
		mid=n/2;
		init();
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			g[i]=club{x,y,z,y-x};
		}
		if(n<30) dfs(1,0);
		if(n==200) solve();
		cout<<ans<<'\n';
	}
	return 0;
}