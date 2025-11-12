#include<bits/stdc++.h>
using namespace std;
bool b[10001];
long long q[11],qf[10001],tl[10001],dp[11],nxt[2000001],mn[10001];
long long n,h[10001],m,kk,cnt,x,yy,z,f[11][10001],y[11][10001],t[11],sum;
struct fd{
	int w,u;
}to[200001];
void add(int u,int v,int w){
	nxt[++cnt]=h[u];
	h[u]=cnt;
	to[cnt]={v,w};
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>kk;
	for(int i=1;i<=m;i++){
		cin>>x>>yy>>z;
		add(x,yy,z);
		add(yy,x,z);
	}
	mn[0]=1e9;
	for(int i=2;i<=n;i++) mn[i]=1e9;
	for(int i=1;i<=n;i++){
		long long k=0;
		for(int j=1;j<=n;j++)
		if(!b[j]&&mn[j]<mn[k])
		k=j;
		b[k]=1;
		for(int j=h[k];j;j=nxt[j]){
			int u=to[j].w,r=to[j].u;
			if(r<mn[u]) mn[u]=r;
		}
	}
	for(int i=1;i<=kk;i++){
		int ll=1;
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
			y[i][j]=f[i][j];
			if(f[i][j]<=mn[j]) y[i][j]=min(y[i][j],mn[j]-f[i][j]);
			if(y[i][j]<f[i][ll]) ll=j;
		}
		t[i]=f[i][ll],q[i]=ll;
	}
	for(int i=1;i<=n;i++) qf[i]=mn[i];
	for(int i=1;i<=kk;i++){
		for(int j=1;j<=n;j++) if(mn[j]>f[i][j]) dp[i]+=mn[j]-f[i][j];
		if(dp[i]>t[i])
		for(int j=1;j<=n;j++) if(mn[j]>f[i][j]) dp[tl[j]]-=mn[j]-f[tl[j]][j];
		else dp[i]=0;
		for(int j=1;j<i;j++)
			if(dp[j]<t[j]&&dp[j]){
				for(int g=1;g<=n;g++)
					if(tl[g]==j) tl[g]=0,mn[g]=qf[g];
				dp[j]=0;
			}
	}
	for(int i=1;i<=n;i++) sum+=mn[i];
	cout<<sum;
	return 0;
}
