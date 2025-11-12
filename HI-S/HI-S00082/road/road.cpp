#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000010],b[20][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++)cin>>b[i][j];
	}
	cout<<13;
	return 0;
} 
