#include<bits/stdc++.h>
using namespace std;
struct Node{
	int u,v,w;
}a[1000005];
int b[1];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.in","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	return 0;
}
