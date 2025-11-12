#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int sum=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		sum+=u+v+w;
	}
	printf("%d",sum);
	return 0;
}
