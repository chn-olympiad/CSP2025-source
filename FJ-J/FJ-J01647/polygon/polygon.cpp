#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005],num[5005],sum[5005],maxsum;
int main()
{
//freopen("xor.in","r",stdin);
//freopen("xor.out","w"stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
	sum[i]=a[i];
}
sort(a+1,a+n+1);
for(int i=n;i>=1;i--){
	for(int j=1;j<i;j++){
		if(sum[i]+a[j]>a[i]*2){
			num[i]++;
			if(num[i]>=3){
				maxsum++;
				sum[i]+=a[j];
			}
			else{
				sum[i]+=a[j];
				num[i]++;
			}
		}
		else{
			sum[i]+=a[j];
			num[i]++;
		}
	}
}
cout<<maxsum;
return 0;
}
