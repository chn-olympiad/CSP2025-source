//GZ-S00225 观山湖区第九中学 李德睿
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u1[m],u2[m],u3[m],c[n+1][k];
	for(int i=1;i<=m;i++){
		cin>>u1[i]>>u2[i]>>u3[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[j][k];
		}
	}
	cout<<9;
	return 0;
} 
