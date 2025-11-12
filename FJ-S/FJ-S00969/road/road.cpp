#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int ans=0;
	for(int i=1; i<=m; i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ans+=z;
	}
	cout<<ans;
	return 0;
} 
