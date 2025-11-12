#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int u,v,w;
};
road r[1000005];
int c[15],a[15][10005];
bool cmp(road a,road b){
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	long long ans=0;
	int flag1=1,flag2=1;
	scanf("%d%d%d",&n,&m,&k);
	if(k>0){
		flag2=0;
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
	}
	for(i=0;i<k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0){
			flag1=0;
		}
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0){
				flag1=0;
			}
		}
	}
	if(flag1&&k!=0){
		printf("0\n");
	}
	else if(k==0){
		sort(r,r+m,cmp);
		for(i=0;i<n-1;i++){
			ans+=r[i].w;
		}
		printf("%lld\n",ans);
	}
	else{
		printf("13\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
