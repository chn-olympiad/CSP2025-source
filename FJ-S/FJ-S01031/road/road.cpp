#include<bits/stdc++.h>
using namespace std;
int n,m,k,l[10005][10005],c[15],a[15][10005],maxn1,maxn2,sum,minsum=99999999;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>l[u][v];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		maxn1=max(maxn1,c[i]);
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			maxn2=max(maxn2,a[i][j]);
		}
	}
	if((maxn1==0)&&(maxn2==0)){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i+=2){
		for(int j=2;j<=n;j+=2){
			sum+=l[i][j];
		}
		minsum=min(minsum,sum);
		sum=0;
	}
	cout<<minsum;
	return 0;
}
