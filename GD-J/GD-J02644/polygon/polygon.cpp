#include<bits/stdc++.h>
using namespace std;
int n,a[50001],dp[5005][5005],ans,sum,C[5005][5005];
void f(){
	C[0][0]=1;
	for(int i=1;i<=5001;i++){
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]%=998244353;
//			cout<<C[i][j]<<" "; 
		}
//		cout<<'\n';
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) sum++;
	}
	sort(a+1,a+n+1);
	if(sum==n){
		f();
//		cout<<C[6][3]<<'\n';
		for(int i=3;i<=n;i++){
//			cout<<C[n+1][i+1]<<'\n';
			ans+=C[n+1][i+1];
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n==4){
		if(a[1]+a[2]+a[3]>a[3]*2) sum++;
		if(a[1]+a[2]+a[4]>a[4]*2) sum++;
		if(a[1]+a[3]+a[4]>a[4]*2) sum++;
		if(a[2]+a[3]+a[4]>a[4]*2) sum++;
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) sum++;
		cout<<sum;
	}else if(n==5){
		if(a[1]+a[2]+a[3]>a[3]*2) sum++;
		if(a[1]+a[2]+a[4]>a[4]*2) sum++;
		if(a[1]+a[2]+a[5]>a[5]*2) sum++;
		if(a[1]+a[3]+a[4]>a[5]*2) sum++;
		if(a[1]+a[3]+a[5]>a[5]*2) sum++;
		if(a[1]+a[4]+a[5]>a[5]*2) sum++;
		if(a[2]+a[3]+a[4]>a[4]*2) sum++;
		if(a[2]+a[3]+a[5]>a[5]*2) sum++;
		if(a[2]+a[4]+a[5]>a[5]*2) sum++;
		if(a[3]+a[4]+a[5]>a[5]*2) sum++;
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) sum++;
		if(a[1]+a[2]+a[3]+a[5]>a[5]*2) sum++;
		if(a[1]+a[2]+a[4]+a[5]>a[5]*2) sum++;
		if(a[2]+a[3]+a[4]+a[5]>a[5]*2) sum++;
		if(a[1]+a[3]+a[4]+a[5]>a[5]*2) sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2) sum++;
		cout<<sum;
	}
} 
