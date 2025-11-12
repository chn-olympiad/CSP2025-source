#include<bits/stdc++.h>
using namespace std;
int f[10001][10001],minn=1e9;
int tmp9,tmp5,tmp6,tmp7,tmp8;
int n,m,k;
struct Node{
	int mf,mr[10001];
}c[11];
bool vis[10001];
void dfs(int now,int step,int ans){
	if(step==n+1){
		minn=min(ans,minn);
		//cout<<minn<<endl;
		return;
	}
	vis[now]=1;
	for(int i=1;i<=n;i++){
		if(f[now][i]==0) continue;
		tmp9=f[now][i];
		for(int j=1;j<=k;j++){
			if(c[j].mr[now]+c[j].mr[i]+c[j].mf<=f[now][i]){
				tmp5=c[j].mr[now],tmp6=c[j].mr[i];
				tmp9=c[j].mr[i]+c[j].mr[now]+c[j].mf;
				tmp8=c[j].mf;
				tmp7=j;
				c[j].mr[now]=0;
				c[j].mr[i]=0;
				c[j].mf=0;
			}
		}
		f[now][i]=0;
		dfs(i,step+1,ans+tmp9);
		f[now][i]=tmp9;
		c[tmp7].mr[now]=tmp5;
		c[tmp7].mr[i]=tmp6;
		c[tmp7].mf=tmp8;
	}
	vis[now]=0;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int tmp1,tmp2,tmp3;
		cin>>tmp1>>tmp2>>tmp3;
		if(f[tmp1][tmp2]!=0){
			tmp3=min(f[tmp1][tmp2],tmp3);
		}
		f[tmp1][tmp2]=tmp3;
		f[tmp2][tmp1]=tmp3; 
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		vis[i]=1;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i].mf;
		for(int j=1;j<=n;j++){
			cin>>c[i].mr[j];
		}
	}
	c[0].mf=0;
	for(int j=1;j<=n;j++){
		c[0].mr[j]=1e8;
	}
	dfs(3,1,0);
	cout<<minn; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
