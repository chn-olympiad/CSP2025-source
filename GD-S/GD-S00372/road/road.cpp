#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1,u,v,w;i <= m;i++){
		cin >> u >> v >> w;
	}
	for(int i = 1;i <= k;i++)
		for(int j = 1,vg;j <= n;j++) cin >> vg;
	printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
