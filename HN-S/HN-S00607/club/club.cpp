#include <bits/stdc++.h>
using namespace std;
int t,n,dian,dd,ans=0;

struct pian{
	int aij;
	int ren;
	int she;
};
pian mm[20005],nn[20005];
pian dui[20005][5];
int m=-1;
int py[3];
void fapai(int pp){
	for(int i=1;i<=3;i++){
		for(int j=i;j<=3;j++){
			if(dui[pp][i].aij<dui[pp][j].aij){
				pian gay=dui[pp][i];
				dui[pp][i]=dui[pp][j];
				dui[pp][j]=gay;
		 }
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		ans=0;
		scanf("%d",&n);
		if(n==1){
			printf("%d\n",ans);
			continue;
		} 
		for(int j=1;j<=n;j++){
			scanf("%d %d %d",&dui[j][1].aij,&dui[j][2].aij,&dui[j][3].aij);
			dui[j][1].ren=j;
			dui[j][1].she=1;
			dui[j][2].ren=j;
			dui[j][2].she=2;
			dui[j][3].ren=j;
			dui[j][3].she=3;
			fapai(j);
			ans+=dui[j][1].aij;
		}
		printf("%d\n",ans);

	
}
return 0;
}
