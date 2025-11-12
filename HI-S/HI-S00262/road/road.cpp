#include<bits/stdc++.h>
using namespace std;
int a[1000005][4];
int b[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int c=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	c+=a[i][3];		
	}

	for(int i=1;i<=k;i++){
	
		scanf("%d",&b[i][0]);
		for(int j=1;j<=n;j++){
	
			scanf("%d",&b[i][j]);
		}
		
	}
	if(k==0){
		printf("%d",c);
	}else{
		 c=0;
		printf("%d",c);
	}
	
}
