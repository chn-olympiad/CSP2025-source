#include<bits/stdc++.h>
using namespace std;
main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,a,sum=0;
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++){
		cin>>u>>v>>a;
		sum+=a;
	}
	cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
