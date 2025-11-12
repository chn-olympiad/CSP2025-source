#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ma[11451][11451],vis[11451],build[11];

long long find(int x,long long money){
	if(vis[x]) return money;
	for(int i=0;i<n+k;i++){
		if(ma[x][i]==0||vis[x]) continue;
		else{
			long long minx=99999999999999999999999;
			vis[x]=1;
			if(i>=n) minx=min(minx,find(i,money+build[i]+ma[i][x]));
			else minx=min(minx,find(i,money+ma[i][x]));
			vis[x]=0;
			money=minx;
		}
		return money;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		long long x,y;
		cin>>x>>y;
		cin>>ma[x-1][y-1];
		ma[y-1][x-1]=ma[x-1][y-1];
	}
	for(int i=0;i<k;i++){
		cin>>build[i];
		for(int j=0;j<n;j++){
			cin>>ma[n+i][j];
			ma[j][i+n]=ma[i+n][j];
		}
	}
	cout<<find(0,0);
}
