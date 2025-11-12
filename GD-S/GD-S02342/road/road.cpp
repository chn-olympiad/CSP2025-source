#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N=1e4+12,M=1e6+12;
int n,m,k,ans=LLONG_MAX,cnt;
int b[12][N],q[12],f[N],Q[12];
struct node{
	int x,y,z;
}a[M];
bool cmp(node x,node y){
	return x.z<y.z;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void dfs(int xx){
	if(xx>k){
		node c[M];//qi¥Ê∂ÓÕ‚µ„ 
		int cn=0;
		for(int i=1;i<=m;i++)
			c[++cn].x=a[i].x,c[cn].y=a[i].y,c[cn].z=a[i].z;
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=n;j++){
				c[++cn].x=q[i]+n,c[cn].y=j,c[cn].z=b[q[i]][j];
			}
		}
		sort(c+1,c+1+cn,cmp);
	/*	for(int i=1;i<=cn;i++){
			cout<<c[i].x<<' '<<c[i].y<<' '<<c[i].z<<endl;
		}*/
		int tot=0,sum=0;
		for(int i=1;i<=n;i++)
			f[i]=i;
		for(int i=1;i<=cnt;i++)
			f[q[i]+n]=q[i]+n,sum+=Q[q[i]];
		for(int i=1;i<=cn;i++){
			if(tot==n+cnt-1){
				ans=min(ans,sum);
				break;
			}
			int X=c[i].x,Y=c[i].y;
			int fx=find(X),fy=find(Y);
			if(fx!=fy){
				f[fx]=fy;
				sum+=c[i].z;
				tot++;
			}
		}
	}else{
		dfs(xx+1);
		q[++cnt]=xx;
		dfs(xx+1);
		cnt--;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].z;
	for(int i=1;i<=k;i++){
		cin>>Q[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 2 3 4

*/
