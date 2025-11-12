#include<bits/stdc++.h>
using namespace std;
int sum=0,m,n,k,u[1000010][3],w[1000010],c[11],a[11][1000010];
bool ap[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i][1]>>u[i][2]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i]>>a[i][j];
			if(a[i][j]==0){
				ap[j]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(!ap[u[i][1]]&&!ap[u[i][2]]){
			sum+=w[i];
		}
	}
	cout<<sum;
	return 0;
}
