#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define f(a,b,c) for(int a=b;a<=c;a++)
#define d(a,b,c) for(int a=b;a>=c;a--)
using namespace std;
const int N=1e4+5;
struct edge{
	int x,y,z;
}e[N*110];
int n,m,k,x,y,z;
int fa[N],ans,cnt,ecnt;
int findfa(int x){
	return fa[x]=(fa[x]==x?x:findfa(fa[x]));
}
bool cmp(edge a,edge b){
	return a.z<b.z;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	f(i,1,n)fa[i]=i;
	f(i,1,m)cin>>x>>y>>z,e[++ecnt]={x,y,z},e[++ecnt]={y,x,z};
	f(i,1,k)f(j,0,n)cin>>x;
	sort(e+1,e+ecnt+1,cmp),cnt=1;
	f(i,1,ecnt){
		if(cnt==n)break;
		int xx=findfa(e[i].x);
		int yy=findfa(e[i].y);
//		cout<<e[i].x<<" "<<e[i].y<<"\n";
		if(xx!=yy)ans+=e[i].z,cnt++,fa[xx]=yy,cout<<xx<<" "<<yy<<"\n";
	}
	cout<<ans;
	return 0;
}
