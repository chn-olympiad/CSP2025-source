#include <bits/stdc++.h>
using namespace std;
long long n,m,k,q[10015][10015],dq[10015],vis[10015],x,y,z;
unsigned long long ans=9999999999;
vector<long long >a[10015];
void ss(long long f,unsigned long long ma){
	ma+=dq[f];
	if(ma>ans) return;
	long long s=0,si=a[f].size();
	for(int i=0;i<si;i++){
		if(vis[a[f][i]]==0){
			s++;
			vis[a[f][i]]=1;
			ss(a[f][i],ma+q[f][a[f][i]]);
			vis[a[f][i]]=0;
		}
	}
	if(s==0){
		ans=min(ans,ma);
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		q[x][y]=z;
		q[y][z]=z;
		a[x].push_back(y);
		a[y].push_back(x);
		dq[x]=0;
		dq[y]=0;
	}
	for(int i=1;i<=k;i++){
		cin>>x;
		dq[n+i]=x;
		for(int j=1;j<=n;j++){
			cin>>y;
			q[n+i][j]=y;
			q[y][n+i]=y;
			a[n+i].push_back(j);
			a[y].push_back(n+i);
		}
	}
	vis[1]=1;
	ss(1,0);
	cout<<ans;
	return 0;
}