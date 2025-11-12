#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;
int  g[MAXN][MAXN],xiang[11][MAXN],n,m,k,xdis[11];
int sum,pan,sum2=0xfffee;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g[x][y]=g[y][x]=z;
		sum+=z;
	}
	for(int i=1;i<=k;i++){
		cin>>xdis[i];
		pan+=xdis[i];
		for(int j=1;j<=n;j++)cin>>xiang[i][j];
	}
	if(pan==0){
		for(int i=1;i<=k;i++){
			int sum3=0;
			for(int j=1;j<=n;j++){
				sum3+=xiang[i][j];
			}
			sum2=min(sum2,sum3);
		}
	}
	sum=sum<sum2?sum:sum2;
	cout<<sum;
	return 0;
} 
