#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n[6],a[100005][3];
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n[i]);
		for(int j=1;j<=n[i];j++){
			scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
		}
	}
	for(int i=1;i<=t;i++){
		int sum[6],maxx[100005],maxxx[100005],c[3];
		for(int j=1;j<=n[i];j++){
			maxx[j]=max(a[j][1],a[j][2]);
			maxxx[j]=max(maxx[j],a[j][3]);
			sum[i]+=maxxx[j];
			if(maxxx[j]==a[j][1]){
				c[1]++;
			}
			else if(maxxx[j]==a[j][2]) c[2]++;
			else c[3]++;
		}
		if((c[1]<=(n[i]/2)) && (c[2]<=(n[i]/2)) && (c[3]<=(n[i]/2))){
			printf("%d",sum[i]);
		}
	}
	return 0;
}
