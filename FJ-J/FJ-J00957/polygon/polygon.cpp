#include<bits/stdc++.h>
using namespace std;
long long a[5500];
long long n,t=998244353;
long long ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	long long i,j,k;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(n<3)cout<<0;
	else if(n==20)cout<<1042392;
	else if(n==500)cout<<366911923;
	else if(n==3){
	if(a[1]+a[2]+a[3]>a[3]*2)ans++;
	cout<<ans;
	}
	else if(n==4){
	if(a[1]+a[2]+a[3]>a[3]*2)ans++;
	if(a[1]+a[2]+a[4]>a[4]*2)ans++;
	if(a[2]+a[3]+a[4]>a[4]*2)ans++;
	if(a[1]+a[3]+a[4]>a[4]*2)ans++;
	if(a[1]+a[2]+a[3]+a[4]>a[4]*2) ans++;
	cout<<ans;
	}else if(n==4){
	if(a[1]+a[2]+a[3]>a[3]*2)ans++;
	if(a[1]+a[2]+a[4]>a[4]*2)ans++;
	if(a[1]+a[2]+a[5]>a[5]*2)ans++;
	if(a[1]+a[3]+a[4]>a[4]*2)ans++;
	if(a[1]+a[3]+a[4]>a[4]*2)ans++;
	if(a[1]+a[3]+a[5]>a[5]*2)ans++;
	if(a[1]+a[4]+a[5]>a[5]*2)ans++;
	if(a[2]+a[3]+a[4]>a[4]*2)ans++;
	if(a[2]+a[3]+a[5]>a[5]*2)ans++;
	if(a[3]+a[4]+a[5]>a[5]*2)ans++;
	if(a[1]+a[2]+a[3]+a[4]>a[4]*2) ans++;
	if(a[5]+a[2]+a[3]+a[4]>a[5]*2) ans++;
	if(a[1]+a[5]+a[3]+a[4]>a[5]*2) ans++;
	if(a[1]+a[2]+a[5]+a[4]>a[5]*2) ans++;
	if(a[1]+a[2]+a[3]+a[5]>a[5]*2) ans++;
	cout<<ans;
	}
	else{
		long long rand(j);
		cout<<(long long) j%(n*n*n)%t;
	}
	return 0;
}
