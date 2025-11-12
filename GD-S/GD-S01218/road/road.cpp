#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
struct aa{
	int w,u,v;
}l[N],ll[N];
int n,m,k,fa[N],cnt=0,a[20][N],c[N];

int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
bool cmp(aa xx,aa yy){
	return xx.w<yy.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin >> l[i].u >> l[i].v >> l[i].w;
	}
	sort(l+1,l+1+n,cmp);
	for(int i=1,x,y;i<=k;i++){
		cin >> x;
		c[i]=x;
		for(int j=1;j<=n;j++){
			cin >> y;
			a[i][j]=y;
		}
	}
	int ss=n;
	long long ans=0;
	for(int i=1;i<=m;i++){
		if(ss==1){
			break;
		}
		int xx=l[i].u,yy=l[i].v;
		int ww=l[i].w;
		int fx=find(xx),fy=find(yy);
		if(fx!=fy){
			ss--;
			fa[fx]=find(fy);
			ans+=ww;
		}
	}
	
	cout << ans;
	return 0;
}
