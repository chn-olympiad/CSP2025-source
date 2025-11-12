#include<bits/stdc++.h>
using namespace std;
int r[10005][10005];
int c[15][10005];
int ret[10005];
int n,m,t;
int res=0;
void prime(int k,int ch){
	if(ch==n-1)return;
	for(int i=1;i<=n;i++){
		if(i!=k&&r[k][i]!=0){
			if(ret[i]==0){
				ret[i]=r[k][i];
				prime(i,ch+1);
			}
			else if(ret>0&&ret[i]>r[k][i]){
				ret[i]=r[k][i];
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		r[x][y]=z;
		r[y][x]=z;
		//cout<<x<<" "<<y<<" "<<z<<endl;
	}
	for(int i=1;i<=t;i++){
		int w;
		cin>>w;
		c[i][0]=w;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	prime(1,0);
	for(int i=2;i<=n;i++){
		res+=ret[i];
		//cout<<ret[i]<<" ";
	}
	cout<<res+1;
	return 0;
}
