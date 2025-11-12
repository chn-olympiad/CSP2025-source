#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10004][10004],w[10004];
long long ans;
bool f[10004];
void A(){
	w[1]=0;
	for(int i=1;i<=n;i++){
		int now,m=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			if(f[j]==0&&w[j]<m){
				now=j;
				m=w[j];
			}
		}
		ans+=m;
		f[now]=1;
		for(int j=1;j<=n;j++){
			if(f[j]==0&&a[now][j]<w[j])w[j]=a[now][j];
		}
	}
	printf("%lld",ans);
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(a,0x3f,sizeof(a));
	memset(w,0x3f,sizeof(w));
	for(int i=1;i<=n;i++)a[i][i]=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=a[y][x]=min(z,a[y][x]);
	}
	if(k==0)A();
	else{
		int b[14][10004];
		for(int i=1;i<=k;i++)
			for(int j=0;j<=n;j++){
				int t;
				scanf("%d",&t);
				b[i][j]=t;
			}
		for(int q=1;q<=k;q++)for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)a[i][j]=a[j][i]=min(a[i][j],b[q][i]+b[q][j]);
		A();
	}
	return 0;
}
