#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,a[100000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
			sort(a+1,a+1+3); 
			if(a[1]+a[2]+a[3]>2*a[3]){
				cout<<1;
			}else{
				cout<<0;
			}                                            
	}else{
		for(int i=3;i<=n;i++){
			ll ss=1,xx=1;
			for(int j=n;j>=i;j--){
				ss*=j;
			}
			for(int j=i;j>=1;j--){
				xx*=j;
			}
			sum+=ss/xx;
		}
		cout<<sum%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
