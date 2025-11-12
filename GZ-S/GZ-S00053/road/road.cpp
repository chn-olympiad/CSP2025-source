//准考证GZ-S00053 学校：都匀二中 名字：刘宇蒙 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct troad{
	int u,v,w;
};troad mytroad[MAXN];
int n,m,k;
int conz[MAXN][MAXN];
int d[MAXN]; 
int ans;
int main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>mytroad[i].u>>mytroad[i].v>>mytroad[i].w;
		d[i]=mytroad[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>conz[i][j];
		}
	}
	for(int i=1;i<n-2;i++){
		for(int j=i+1;j<=m;j++){
			int lu;
			if(d[i]>d[j]){
				lu=d[i];
				d[i]=d[j];
				d[j]=lu;
			}
		}
		ans+=d[i];
	}
	for(int i=2;i<=n;i++){
		if(conz[1][1]>conz[1][i]){
				int llz;
				llz=conz[1][1];
				conz[1][1]=conz[1][i];
				conz[1][i]=llz;
			}
	}
	cout<<ans+conz[1][1];
	return 0;
}
