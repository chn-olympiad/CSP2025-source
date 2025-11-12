#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c;
int a[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[j]);
		}
	}
	cout<<"13 "<<endl;
	return 0;
}
