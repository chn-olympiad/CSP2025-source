#include<bits/stdc++.h>
using namespace std;
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int ui,vi,wi;
		scanf("%d%d%d",&ui,&vi,&wi);
	}
	for(int i=1;i<=k;++i){
		int num;
		scanf("%d",&num);
		ans+=num;
		for(int j=1;j<=n;++j) scanf("%d",&num); 
	}
	printf("%d",ans);
	return 0;
}

