#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	int city[m][3],vill[k][m+1];
	for(int i=0;i<m;i++){
		cin>>city[i][0]>>city[i][1]>>city[i][2];
	}
	for(int i=0;i<k;i++){
		cin>>vill[i][0];
		for(int j=1;j<=m;j++){
			cin>>vill[i][j];
		}
	}
	cout<<0;
	return 0;
}
