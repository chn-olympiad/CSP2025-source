#include<bits/stdc++.h> 
using namespace std;
const long long N=998244353; 
int n,a[5010],num=0;
long long x=1,y=1,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
		if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			num++;
		}
	}
	if(n==3){
		num=max(a[1],a[2]);
		if(a[1]+a[2]+a[3]>max(num,a[3])*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	
	if(num==n){
		for(int i=3;i<=n;i++){
			for(int j=1;j<=i;j++){
				x*=j; 
			}
			for(int j=1;j<=n;j++){
				y*=j; 
			}
			y/=x;
			for(int j=1;j<=n-i;j++){
				x*=j;
			}
			ans+=y/x;
		}
		cout<<ans%N;
	}
	return 0;
}
