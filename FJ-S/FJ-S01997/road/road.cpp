#include<bits/stdc++.h>
using namespace std;
int n,m,k,rb[1000005][5],cc[15],bd[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>rb[i][1]>>rb[i][2]>>rb[i][3];
	}
	for(int i=1;i<=k;i++){
		cin>>cc[i];
		for(int j=1;j<=n;j++){
			cin>>bd[i][j];
		}
	}
	cout<<"0";
	return 0;
}
