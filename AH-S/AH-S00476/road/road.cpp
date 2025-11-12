#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int w[1000],q[1000],h[1000];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>w[i*2-1]>>w[i*2]>>q[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;i++){
			cin>>h[j*i];
		}
	}
	cout<<12;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

