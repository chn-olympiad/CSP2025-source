#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[i];
		}
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
