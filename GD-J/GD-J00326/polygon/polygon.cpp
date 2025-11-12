#include<iostream>
using namespace std;
long long C(int x,int y){
	long long num=1;
	for(int i=x;i>=x-y+1;i++){
		num*=i;
	}
	for(int i=y;i>=1;i--){
		num/=i;
	}
	return num;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	int arr[n+100]={};
	for(long long i=0;i<n;i++){
		cin>>arr[i];
	}for(long long i=n;i>=3;i--){
		ans+=C(n,i)%998244353;
	}
	cout<<ans;
	return 0;
}
