#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[5005]={},ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long l=1,r=3;
	while(r-l+1>=3){
		long long num=0,m=0;
		for(long long i=l;i<=i;i++){
			num+=a[i];
			m=max(a[i],n);
		}
		if(m*2<num){
			ans++;
		}
		if(r<n){
			r++;
		}
		else{
			l++;
			r=l+2;
		}
	}
	ans%=998244353;
	cout<<ans;
	return 0;
}
