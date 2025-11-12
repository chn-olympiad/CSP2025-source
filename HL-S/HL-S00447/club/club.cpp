#include<bits/stdc++.h>
#define MAX_N 1000
int cmp(const void*a,const void*b){
	return *(int *)b-*(int *)a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int max_per_dept=n/2;
		int a1[MAX_N],a2[MAX_N],a3[MAX_N];
		int cnt1=0,cnt2=0,cnt3=0;
		long long total =0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a1[i],a2[i],a3[i]);
		}
		for(int i=0;i<n;i++){
			int max_val=-1;
			int choice=0;
			if(cnt1< max_per_dept && a1[i]>max_val){
				max_val=a1[i];
				choice =1;
			}
			if(cnt2< max_per_dept && a2[i]>max_val){
				max_val=a2[i];
				choice =2;
			}
			if(cnt1< max_per_dept && a3[i]>max_val){
				max_val=a3[i];
				choice =3;
			}
			total+=max_val;
			if(choice==1) cnt1++;
			else if(choice==2) cnt2++;
			else cnt3++;
		}
			printf("%lld\n",total);
		}
			return 0;

	}


