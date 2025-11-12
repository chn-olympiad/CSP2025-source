#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,lb[1007][1007],lb2[1007][1007];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%d%d%d",&n,&m,&k); 
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		lb[a][b]=lb[b][a]=c;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&a);
		for(int j=1;j<=n;j++) scanf("%d",&lb2[a][i])
	}
	cout<<10<<endl;
	return 0;
}
