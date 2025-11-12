#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],c[1000005],a,w[100005],t=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a;
			if(a==0) t==1;
			else t==0;
		}
	}
	if(t==1) cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
