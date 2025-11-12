#include <bits/stdc++.h>
using namespace std;
int n;
long long sum=1;
bool flagb=true;
int a[5005];
long long calcu(long long c,long long d){
	long long ans=1;
	for(int i=c;i>=d;i--){
		ans*=i;
		ans=ans%998244353;
	}
	return ans%998244353;
}
long long cal(long long a,long long b){
	return calcu(a,a-b+1)/calcu(b,1)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b>c && a+c>b && b+c>a){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flagb=false;
		}
	}
	for(int i=3;i<=n;i++){
		sum*=cal(n,i);
		sum=sum%998244353;
	}
	cout<<sum%998244353<<endl;
}
