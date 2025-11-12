#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
/*struct xcy{
	int ma[N],mb[N],mc[N];
};*/
int main(){
	int n,a[N],b[N],c[N],cnt1=0,cnt2=0,cnt3=0,sum1=0,sum2=0,sum3=0,mi;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	mi=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]>b[i]&&a[i]>c[i]){
			cnt1++;
			sum1+=a[i];
			if(a[i]<mi){
				mi=a[i];
			}
		}else if(b[i]>a[i]&&b[i]>c[i]){
			sum2+=a[i];
			cnt2++;
			if(a[i]<mi){
				mi=a[i];
			}
		}else if(c[i]>a[i]&&c[i]>b[i]){
			cnt3++;
			sum3+=a[i];
			if(a[i]<mi){
				mi=a[i];
			}
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			cout<<sum1+sum2+sum3;
			break;
		}else if(cnt1>n/2||cnt2>n/2||cnt3>n/2){
			if(sum1>n/2&&sum1>sum2&&sum1>sum3&&sum2>sum3){
				cnt1--;
				cnt3++;
				sum1-mi;
			}else if(sum2>n/2&&sum1>sum3&&sum2>sum1&&sum2>sum3){
				cnt2--;
				cnt3++;
				sum2-mi;
			}else if(sum3>n/2&&sum3>sum1&&sum1>sum2&&sum3>sum2){
				cnt3--;
				cnt2++;
				sum3-mi;
			}
			cout<<sum1+sum2+sum3;
			break;
		}
	}
	return 0;
}
