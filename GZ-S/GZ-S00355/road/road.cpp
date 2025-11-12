// GZ-S00355 程袁浩 华师一 
#include <bits/stdc++.h>
#define int long long
#define upp(a,x,y) for(int a=x;a<=y;a++)
#define dww(a,x,y) for(int a=x;a>=y;a--)
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
const int N=2e6+10,M=1e4+10;
bool st[M];
int a[20][M];
int c[N];
int minn[M];
struct node {
	int x,y,z;
}edges[N];
int cnt=0;
bool cmp(node x,node y) {
	cnt++;
	return x.z<y.z;
}
int n,m,kk;
int fa[N],siz[N];
int find(int x,int dep=1) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x],dep+1);
}
void merge(int x,int y) {
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	if(siz[fx]>siz[fy]) swap(fx,fy);
	fa[fx]=fy;
	siz[fy]+=siz[fx];
}
void solve() {
    cin>>n>>m>>kk;
	//double now=clock();
    upp(i,1,m) {
    	//int x,y,z;cin>>x>>y>>z;
    	cin>>edges[i].x>>edges[i].y>>edges[i].z;
	}
	//cerr<<clock()-now<<endl;
	upp(i,1,kk) {
		cin>>c[i];
		upp(j,1,n) cin>>a[i][j];
	}
	upp(i,1,n) fa[i]=i,siz[i]=1;
	sort(edges+1,edges+1+m,cmp);
	int sum=0;
	upp(i,1,m) {
		int x=edges[i].x,y=edges[i].y,z=edges[i].z;
		if(find(x)==find(y)) continue;
		merge(x,y);
		sum+=z;
	}
	upp(i,0,(1<<kk)-1) {
		int top=0,res=0;
		vector<node> nes;
		upp(j,0,kk-1) {
			if(i>>j&1) {
				res+=c[j+1];
				upp(k,1,n) {
					nes.pb((node){n+j+1,k,a[j+1][k]});
				}
			} 
		}
		sort(nes.begin(),nes.end(),cmp);
		upp(j,1,n+kk) fa[j]=j,siz[j]=1;
		upp(j,1,m) {
			int x=edges[j].x,y=edges[j].y,z=edges[j].z;
			while(top<(int)nes.size()&&nes[top].z<z) {
				int xx=nes[top].x,yy=nes[top].y,zz=nes[top].z;
				if(find(xx)==find(yy)) {
					top++;
					continue;
				}
				merge(xx,yy);
				res+=zz;
				top++;
			}
			if(find(x)==find(y)) continue;
			merge(x,y);
			res+=z;
			cnt++;
		}
		sum=min(sum,res);
	}
	cout<<sum<<endl;
}
signed main() {
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int tt;tt=1;
    while(tt--) solve();
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
