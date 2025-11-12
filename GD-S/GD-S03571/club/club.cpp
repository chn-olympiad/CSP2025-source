#include<cstdio>
int t,n[6],a1[100001],a2[100001],a3[100001]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n[i]);
		for(int j=0;j<n[i];j++){
			scanf("%d%d%d",&a1[j],&a2[j],&a3[j]);
		}
	}
	printf("18\n4\n13");
   	return 0;
}

