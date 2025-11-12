#include "bits/stdc++.h"
using namespace std;
int tot1,tot2,tot3,a[100001][3],sorts1[100001],sorts2[100001],sorts3[100001];
int main(void){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0;
		scanf("%d",&n);
		tot1=tot2=tot3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){sorts1[++tot1]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);continue;}
			if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){sorts2[++tot2]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);continue;}
			if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){sorts3[++tot3]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);continue;}  
		}
		if(tot1>n/2){
			sort(sorts1+1,sorts1+tot1+1);
			for(int i=1;i<=tot1-n/2;i++) ans-=sorts1[i];
		}
		if(tot2>n/2){
			sort(sorts2+1,sorts2+tot2+1);
			for(int i=1;i<=tot2-n/2;i++) ans-=sorts2[i];
		}
		if(tot3>n/2){
			sort(sorts3+1,sorts3+tot3+1);
			for(int i=1;i<=tot3-n/2;i++) ans-=sorts3[i];
		}printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
} 
