#include<bits/stdc++.h>
using namespace std;
struct road{
	int u,v,w;
};
int a[5005][5005],flag[100005],b[15][100005],f[10005],cnt=0,n,m,k;
road c[100005];
void prim(){
	
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=1;j<=n;j++){
			if(flag[j]==0&&f[j]<f[t]){
				t=j;
			}
		}
	//	cout<<f[t]<<" "<<t<<endl;
		flag[t]=1;
		cnt+=f[t];
		for(int j=1;j<=n;j++){
			if(flag[j]==0&&f[j]>f[t]+a[j][t]){
				//cout<<j<<" "<<t<<endl;
				f[j]=a[j][t];
			}
		}
	}
	
}
bool cmp(road x,road y){
	return x.w>y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&c[i].u,&c[i].v,&c[i].w);
		a[c[i].u][c[i].v]=a[c[i].v][c[i].u]=c[i].w;	
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++){
			scanf("%d",&b[i][j]);
			if(b[i][j]!=0){
				flag=1;
			}
		}
	}
	sort(c+1,c+m+1,cmp);
	if(k!=0){
		if(!flag){
			for(int i=1;i<=k;i++){
				c[i].w=0;
			}
		}else{
			int flag=1;
			for(int i=1;i<=m&&flag<=k;i++){
				if(c[i].w>b[flag][c[i].u]+b[flag][c[i].v]+b[flag][0]){
					c[i].w=b[flag][c[i].u]+b[flag][c[i].v]+b[flag][0];
					flag++;
				}
			}
		}
	}
	
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i]=a[1][i];
	}
	//
	f[1]=0;
	//cout<<f[0]<<endl;
	prim();
	cout<<cnt;
	return 0;
}
