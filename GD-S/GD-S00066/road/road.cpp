#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10020][10020],b[110],ans[10020],x,y,z,p=1,q,mi=0x3f3f3f3f,ans2;
bool f[10020]={0,1},r;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(ans,0x3f,sizeof(ans));
	memset(a,-1,sizeof(a));
	ans[1]=0;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>b[n+i];
		for(int j=1;j<=n;j++){
			cin>>y;
			a[n+i][j]=b[k]+y;
			a[j][n+i]=b[k]+y;
		}
	}
	for(int i=1;i<n+k;i++){
		mi=INT_MAX;r=true;
		for(int j=1;j<=n+k;j++){
			if(a[p][j]!=-1){
				ans[j]=min(ans[j],a[p][j]+b[j]);
			}
			if(ans[j]<mi&&(!f[j])){
				mi=ans[j];
				q=j;
			}
		}
		f[q]=true;
		ans2+=ans[q];
		b[q]=0;
		p=q;
		for(int j=1;j<=n;j++){
			if(!f[j]){
				r=false;
				break;
			}
		}
		if(r){
			break;
		}
	}
	cout<<ans2;
	return 0;
}
