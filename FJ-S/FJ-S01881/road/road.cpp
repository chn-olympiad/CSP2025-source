#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(road.in,"r",stdin);
	freopen(road.out,"w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int u[m],v[m],w[m];
	for(int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	int a[k][n];
	int kd[k];
	for(int j=1;j<=k;j++){
		cin >> kd[j];
		for(int l=1;l<=n;l++){
			cin >> a[j][l];
		}
	}
	int sum;
	int smalls = 1000000000000;
	int small = 1000000000000;
	for(int i=1;i<=m;i++){
		if(u[i]>v[i]){
			int t=u[i];
			u[i]=v[i];
			v[i]=t;
		}
	}
	long long sum1[n];
	for(int i=1;i<=m;i++){
		int road[n];
		for(int j=1;j<=n;j++){
			road[j]=0;
		}
		for(int j=1;j<=m;i++){
			if(u[j]==i){
				sum1[i]+=w[j];
				road[i]=1;
			}
		}
		int linshisum=0;
		for(int z=1;z<=k;z++){
			for(int o=1;o<=n;o++){
				if(road[o]==0){
					linshisum+=a[z][o];
				}
			}
			if(sum1[i]+linshisum<=smalls){
				smalls=sum1[i]+linshisum;
			}
		}
		sum1[i]=linshisum;
	}
	for(int i=1;i<m;i++){
		if(sum1[i]<=small){
			small=sum1[i];
		}
	}
	cout << small;
	return 0;
}
