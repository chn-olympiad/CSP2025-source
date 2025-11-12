#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5005];
int b[5005];
int mod=998244353;
//void init(){
//	for(int i=0;i<=5001;i++){
//		b[i]=0;
//	}
//	return;
//}
int check(int x){
	int cnt=0;
	while(x!=0){
		if(x%2==1)cnt++;
		x/=2;
	}
	return cnt;
}
int f(int x){
	int cnt=0;
	while(x!=0){
		cnt++;
		x/=2;
	}
	return cnt;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int cho;
	for(cho=0;cho<=pow(2,n);cho++){
		int num=check(cho);
		int sum=0;
		if(num<3)continue;
		int mx=a[f(cho)];
		int s=1;
		for(int i=cho;i>0;){
			if(i%2==1){
				sum+=a[s];
			}
			s++;
			i/=2;
		}
		if(sum<=2*mx)continue;
		cnt++;	
		cnt%mod;
	
	}
	cout<<cnt;
	return 0;

}
//	for(int i=3;i<=n;i++){
//		init();
//		for(int j=1;j<=n-3;j++){
//			int sum=0;
//			for(int k=j;k<=i;k++){
//				sum+=a[k];
//			}
//			if(sum<=a[j+i]*2)continue;
//			
//		}
//	}
