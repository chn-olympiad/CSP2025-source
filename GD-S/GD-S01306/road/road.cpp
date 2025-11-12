#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=2e4+5;
const int M=1e6+5;
struct edge{
	int x,y;
	long long s;
}g[M*2];
int a[15][N];
int f[N];
long long ans;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}	
bool in[15],v[15];
long long kr(int n,int m){
//	return 0;
	sort(g+1,g+1+m,[](edge x,edge y){
		return x.s<y.s;
	});
	for(int i=1;i<=n;i++)f[i]=i;
	int num=0;
	long long res=0;
	for(int i=1;i<=m;i++){
		int fx=find(g[i].x),fy=find(g[i].y);
		if(fx==fy)continue;
		f[fx]=fy;
		res+=g[i].s;
		num++;
	}
	if(num!=n-1)return 1e18;
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	system("fc road.out road2.ans");
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>g[i].x>>g[i].y>>g[i].s;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)cin>>a[i][j];
	}
	ans=kr(n,m);
	for(int i=1;i<(1<<k);i++){
		long long tmp=0;
		int cntn=n,cntm=m;
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i){
				tmp+=a[j][0];
				cntn++;
				for(int p=1;p<=n;p++){
					g[++cntm]={cntn,p,a[j][p]};
				}
			}
		}
		tmp+=kr(cntn,cntm);
		ans=min(tmp,ans);
	}
	cout<<ans;
}
//8822021617
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
