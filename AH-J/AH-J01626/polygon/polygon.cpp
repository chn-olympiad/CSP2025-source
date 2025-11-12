#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n+1,cmp);
	if(n<3)cout<<0;
	else if(n==3&&a[1]+a[2]>a[3])cout<<1;
	else if(n==3&&a[1]+a[2]<=a[3])cout<<0;
	else if(a[1]==a[n]){
		long long sum=1;
		long long q=3;
		long long ans=0;
		do{
			for(int i=q+1;i<=n;i++){
				sum=sum*i;
				sum=sum%998;
				sum%=244;
				sum%=535;
				num[i]=
			}
			ans+=sum;
			q++;
			sum=q;
		}while(q<n);
		ans++;
		cout<<ans;
	}else cout<<n/2;
//	 for(int i=3;i<=n;i++){ 
//		long long ans=0,cnt=0;
	//	for(int k=1;k<i;k++){
	//		long long sum=0;
	//		for(int j=k;j<i;j++){
	//			sum+=a[j],cnt++;
	//			if(sum>=a[i]&&j>=2){
	//				ans+=i-cnt+j+1;
	//			}
	//		}
	//	}
	//	cout<<ans;
	//}
	return 0;
}
