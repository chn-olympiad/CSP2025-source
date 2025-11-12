//GZ-S00484 贵阳市新世界学校 陶元铀
#include<bits/stdc++.h>
using namespace std;
int t,manyi1,manyi2,manyi3,sum1=0,sum2=0,sum3=0,max1=-1,max2=-1,max3=-1,max4=-1,min1=100000,min2=100000,max5=-1,cnt=0,tmp=3,man1=0,man2=0,man3=0,tyy1=0,tyy2=0,tyy3=0,a[100000],b[100000],c[100000];
long long n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>n;
		sum1=0;
		sum2=0;
		sum3=0;
		int max3=-1,max4=-1,max5=-1,cnt=0,tmp=3,tyy1=0,tyy2=0,tyy3=0,a[100000]={0},b[100000]={0},c[100000]={0};
		for(int j=1;j<=n;++j){
			cin>>manyi1>>manyi2>>manyi3;
			int max1=-1,max2=-1,cnt1=0,cnt2=0,cnt3=0,min1=100000,min2=100000,min3=100000,man1=0,man2=0,man3=0;
			max1=max(manyi1,manyi2);
			max2=max(max1,manyi3);
			cnt+=max2;
			if(max2==manyi1){
				sum1++;
				man1+=max2;
				cnt1=max(manyi2,manyi3);
				tyy1=man1-cnt1;
				min1=min(min1,tyy1);
				a[j]=min1;
			}else if(max2==manyi2){
				sum2++;
				man2+=max2;
				cnt2=max(manyi1,manyi3);
				tyy2=man2-cnt2;
				min2=min(min2,tyy2);
				b[j]=min2;
			}else if(max2==manyi3){
				sum3++;
				man3+=max2;
				cnt3=max(manyi1,manyi2);
				tyy3=man3-cnt3;
				min3=min(min3,tyy3);
				c[j]=min3;
			}
		}
		max3=max(sum1,sum2);
		max4=max(max3,sum3);
		if(max4<=n/2){
			cout<<cnt<<"\n";
		}else if(max4>n/2&&max4==sum1){
			for(int k=1;k<=sum1-n/2;++k){
				cnt-=a[k];
			}
			cout<<cnt<<"\n";
		}else if(max4>n/2&&max4==sum2){
			for(int k=1;k<=sum2-n/2;++k){
				cnt-=b[k];
			}
			cout<<cnt<<"\n";
		}else if(max4>n/2&&max4==sum3){
			for(int k=1;k<=sum3-n/2;++k){
				cnt-=c[k];
			}
			cout<<cnt<<"\n";
		}
	}
	
	return 0;
} 
