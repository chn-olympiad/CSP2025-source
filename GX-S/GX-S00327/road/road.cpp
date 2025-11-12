#include <bits/stdc++.h>
using namespace std;

int city[10001][10001];
int ne[10001];
int ans[10003];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,c,x;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		ans[i]=99999;
	}
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		if(a>b){
			swap(a,b);
		}
		city[a][b]=c;
	}
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>ne[j];
			for(int k=1;k<j;k++){
				if(!city[k][j]){
					city[k][j]=ne[k]+ne[j]+x;
				}else{
					city[k][j]=min(city[k][j],ne[k]+ne[j]+x);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int m=1;m<n;m++){
				if(city[j][i]<ans[m]){
					for(int o=m+1;o<n;o++){
						ans[o]=ans[o-1];
					}
					ans[m]=city[j][i];
					break;
				}
			}
		}
	}
	int anss=0;
	for(int i=1;i<n;i++){
		anss+=ans[i];
	}
	cout<<anss;
	return 0;
}
