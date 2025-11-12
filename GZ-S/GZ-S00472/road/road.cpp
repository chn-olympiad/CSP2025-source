//GZ-S00472 遵义市南白中学 陈梓睿
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
ll sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

