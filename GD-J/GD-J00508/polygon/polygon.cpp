#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10001]={0},b[101]={0},sum=0,mod=998244353;
	cin>>n;
	if(n<3){cout<<"0";return 0;}
	else {if(n==3){cin>>a[1]>>a[2]>>a[3];sort(a+1,a+3);if(a[1]+a[2]>a[3])cout<<"1";else cout<<"0";return 0;}}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[a[i]]++;
	}
	if(b[1]==n){
		for(int i=3;i<=n;++i){
			int sum1=1;
			for(int j=n;j>=(n-i+1);--j)sum1*=j;
			for(int j=1;j<=i;++j)sum1/=j;
			sum+=sum1;
			sum%=mod;
		}
	}
	cout<<sum;
	return 0;
}
