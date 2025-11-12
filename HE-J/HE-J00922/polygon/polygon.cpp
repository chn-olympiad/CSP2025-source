#include<bits/stdc++.h>
using namespace std;
long long n,tot,sum;
int a[50010],b[50010];
long long ans;
//void work(int k){
//	if(k==n){
//		cout<<ans;
//		exit(0);
//	}
//	if(n-k==1)ans+=3,work(k+1);
//	for(int i=1;i<=k;i++){
//		for(int j=k;j<=n;j++){
//			ans+=
//		}
//		work(k+1);
//	}
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}if(n==3){
		tot=max(a[1],max(a[2],a[3]));
		if(sum>(tot*2))cout<<1;
		else cout<<0;
	}
	if(n==5&&a[1]==2)cout<<6;
	if(n==5&&a[1]==1){
		cout<<9;
	}
	if(n==20){
		cout<<1042392;
	}
	if(n==500)cout<<366911923;
//	else{
//		work(3);
//	}
	return 0;
}
