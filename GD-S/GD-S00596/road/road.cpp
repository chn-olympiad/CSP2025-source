#include<bits/stdc++.h>
#define int long long
const int N=2e4+5,M=2e6+5;
using namespace std;
int n,m,k,minn,num,ans=1e18,cnt;
int d[15],a[15][N],c[N],f[2][15];
struct Road{
	int u,v,w;
	bool operator<(const Road&A)const{
		return w<A.w;
	}
}r[M];
int find(int k){
	if(c[k]==k)return k;
	return c[k]=find(c[k]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>r[i].u>>r[i].v>>r[i].w;
	for(int i=1;i<=k;i++){
		num=0;
		cin>>d[i];num+=d[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			r[++m]=(Road){i+n,j,a[i][j]};
		}
	}
	for(int i=0;i<(1<<k);i++){
		if(num==0)i=(1<<k)-1;
		minn=cnt=0;
		for(int j=1;j<=n+k;j++)c[j]=j;
		for(int j=1;j<=k;j++){
			if((i&(1<<(j-1)))!=0)minn+=d[j];
		}
		sort(r+1,r+m+1); 
		for(int j=1;j<=m;j++){
			if(r[j].u>n&&(i&(1<<(r[j].u-n-1)))==0)continue;
			int x=find(r[j].u),y=find(r[j].v);
			if(x!=y){
				if(!(r[j].u>n&&r[j].u==x))cnt++;
				if(r[j].u>n)f[0][r[j].u-n]++,f[1][r[j].u-n]=r[j].w;
				c[x]=y,minn+=r[j].w;
				if(cnt==n)break;
			}
		}
		if(num==0){
			for(int i=1;i<=k;i++){
				if(f[0][i]==1)minn-=f[1][i];
			}
		}
		ans=min(ans,minn);
	}
	cout<<ans;
	return 0;
}//72orzorz
