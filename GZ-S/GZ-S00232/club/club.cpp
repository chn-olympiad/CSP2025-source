//GZ-S00232 贵阳市观山湖区外国语实验中学 李治霖  
#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>n;
	int tmp,t[5],ma=INT_MIN,sum=0,cnt1=0,cnt2=0,cnt3=0,h,l;
	while(n--){
		cin>>tmp;
		h=tmp/2;
		for(int i=1;i<=tmp;i++){
			for(int j=1;j<=3;j++)cin>>a[j];
			for(int j=1;j<=3;j++)
				ma=max(ma,a[i]);
			for(int j=1;j<=3;j++){
				if(a[j]==ma){
					cnt1++;
					continue;
				}else if(a[j+1]==ma){
					cnt2++;
					continue;
				}else if(a[j+2]==ma){
					cnt3++;
					continue;
				}
			}
			t[i]=ma;
		}
	}
	for(int i=1;i<=tmp;i++){
		if(cnt1-1<=h&&cnt2-1<=h&&cnt3-1<=h){
			sum+=t[i];
		}else{
			if(cnt1>h){
				i+=cnt1-h;
			}		
			if(cnt2>h){
				i+=cnt2-h;
			}
			if(cnt3>h){
				i+=cnt3-h;
			}
		}
			b[i]=sum;
			
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]+2;
	} 
	return 0;
}

