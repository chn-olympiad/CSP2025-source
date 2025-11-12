#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		int a[m+2][4];
		int cnt1=0,cnt2=0,cnt3=0;
		int sum1=0,sum2=0,sum3=0;
		for(int j=1;j<=m;j++){
			scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
		}
		int w;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=3;k++){
				int maxx=-1;
				if(cnt1==n/2){
					a[j][1]=0;
				}
				if(cnt2==n/2){
					a[j][2]=0;
				}
				if(cnt3==n/2){
					a[j][3]=0;
				}
				if(a[j][k]>maxx){
					maxx=a[j][1];
					w=k;
				}
			}
			if(w==1){
				cnt1++;
				sum1+=a[j][w];
			}else if(w==2){
				cnt2++;
				sum2+=a[j][w];
			}else{
				cnt3++;
				sum3+=a[j][w];
			}
		}
		printf("%d\n",(sum1+sum2+sum3));
	}
	return 0;
} 
