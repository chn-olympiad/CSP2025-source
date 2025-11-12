#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,m;
	scanf("%d",&t);
	for(int v=1;v<=t;v++){
		scanf("%d",&n);
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",a[i][j]);
			}
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			maxn+=a[i][1];
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
		 	maxn+=a[i][2];
		else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])
		 	maxn+=a[i][3];
	}
		printf("%d",maxn);
	}
	return 0;
}
