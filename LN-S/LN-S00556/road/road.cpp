#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
int u[1000001],v[1000001],w[1000001];
int c[12],a[12][10001];
int x[1000001];
int sum;
int all;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		x[i]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sum=m+1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=1;l<=k;l++){
				x[sum]=x[sum]+c[l]+a[l][i]+a[l][j];
				sum++;
			}
		}
	}
	sort(x+1,x+sum);
	for(int i=1;i<=n-1;i++){
		all+=x[i];
	}
	cout<<all;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
