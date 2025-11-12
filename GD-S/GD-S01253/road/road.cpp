#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	int m,n,k,a[1005][5],b[1007][13],s=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		s+=a[i][3];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}
	cout<<s;
}
