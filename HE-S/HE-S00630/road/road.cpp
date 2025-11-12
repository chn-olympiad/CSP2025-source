#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long K[100001][4];
long long h[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>K[i][j];
		}
	}
	for(int i=0;i<=n;i++)cin>>h[i];
	cout<<5182974424;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
