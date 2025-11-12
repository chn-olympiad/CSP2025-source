#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10;
const int M=1e6+10;
int fa[N],ans,g,minn=1e9;
int n,m,k;
int u,v,w;
int c[15],f[15][N],p;
bool flag=1;
vector<pair<int,int> > b[N];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
struct node{
	int x,y,w;
}a[M];
struct node1{
	int u,v;
}d[M];
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int krusal(){
	int s=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=a[i].x,y=a[i].y;
		x=find(x),y=find(y);
		if(x==y) continue;
		fa[x]=y;
		ans+=a[i].w;
		if(++s==n-1) break;
	}
	if(s!=n-1) return -1;//²»Á¬Í¨ 
	else return ans;
}
int krusal1(){
	int s=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=p;i++){
		int x=find(d[i].u),y=find(d[i].v);
		if(x==y) continue;
		fa[x]=y;
		if(++s==n-1) break;
	}
	if(s==n-1) return 0;
	else return -1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].w;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=0;
		bool k1=1;
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
			b[i].push_back({j,f[i][j]});
			b[j].push_back({i,f[i][j]});
			if(f[i][j]==0) k1=0;
		}
		if(k1) flag=0;
	}
	int l=krusal();
	if(k==0){
		write(l);
		putchar('\n');
		return 0;
	}
	if(flag){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(f[i][j]==0){
					++p;
					d[p].u=i,d[p].v=j; 
				}
			}
		}
		int ans2=krusal1();
		if(ans2==0){
			write(ans2);
			putchar('\n');
			return 0;
		}
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/

