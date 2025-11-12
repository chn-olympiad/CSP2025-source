#include<bits/stdc++.h>
using namespace std;
long long a[100005][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long sum,max1,max2,max3;
	int n,cnt1,cnt2,cnt3,t;
	scanf("%d",&t);
	while(t--){
		max1=1;
		max2=1;
		max3=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[max1][1]<a[i][1]){
				max1=i;
			}
			if(a[max2][2]<a[i][2]){
				max2=i;
			}
			if(a[max3][3]<a[i][3]){
				max3=i;
			}
		}
		cnt1=0;
		cnt2=0;
		cnt3=0;
		sum=0;
		for(int i=1;i<=n/2*3;i++){
			if(max1==max2&&max2==max3&&max1==max3){
				if((a[max1][1]>a[max1][2]&&a[max1][1]<a[max1][3]&&cnt1<n/2)||(a[max1][1]>a[max1][3]&&a[max1][1]<a[max1][2]&&cnt1<n/2)){
					sum+=a[max1][1];
					cnt1++;
					a[max1][1]=0;
					a[max1][2]=0;
					a[max1][3]=0;
				}else if((a[max2][2]>a[max2][1]&&a[max2][2]<a[max2][3]&&cnt2<n/2)||(a[max2][2]>a[max2][3]&&a[max2][2]<a[max2][1]&&cnt2<n/2)){
					sum+=a[max2][2];
					cnt2++;
					a[max2][2]=0;
					a[max2][1]=0;
					a[max2][3]=0;
				}else if((a[max3][3]>a[max3][2]&&a[max3][3]<a[max2][1]&&cnt2<n/2)||(a[max3][3]>a[max3][1]&&a[max3][3]<a[max2][2]&&cnt2<n/2)){
					sum+=a[max3][3];
					cnt2++;
					a[max3][2]=0;
					a[max3][1]=0;
					a[max3][3]=0;
				}
			}
			if(a[max1][1]>a[max1][2]&&a[max1][1]>a[max1][3]&&cnt1<n/2){
				sum+=a[max1][1];
				cnt1++;
				a[max1][1]=0;
				a[max1][2]=0;
				a[max1][3]=0;
			}
			if(cnt1+cnt2+cnt3==n){
				break;
			}
			if(a[max2][2]>a[max2][1]&&a[max2][2]>a[max2][3]&&cnt2<n/2){
				sum+=a[max2][2];
				cnt2++;
				a[max2][2]=0;
				a[max2][1]=0;
				a[max2][3]=0;
			}
			if(cnt1+cnt2+cnt3==n){
				break;
			}
			if(a[max3][3]>a[max3][2]&&a[max3][3]>a[max3][1]&&cnt3<n/2){
				sum+=a[max3][3];
				cnt3++;
				a[max3][3]=0;
				a[max3][1]=0;
				a[max3][2]=0;
			}
			if(cnt1+cnt2+cnt3==n){
				break;
			}
			max1=1;
			max2=1;
			max3=1;
			for(int i=1;i<=n;i++){
				if(a[max1][1]<a[i][1]){
					max1=i;
				}
				if(a[max2][2]<a[i][2]){
					max2=i;
				}
				if(a[max3][3]<a[i][3]){
					max3=i;
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
