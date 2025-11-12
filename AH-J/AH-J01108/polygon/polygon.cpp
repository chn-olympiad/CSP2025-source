#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
//Must
long long num1(long long s,long long x,long long cnt,long long maxn){
	if(x==0){
		if(maxn*2<cnt){
			return 1;
		}else{
			return 0;
		}
	}
	long long sum=0;
	for(int i=s+1;i<=n-x+1;i++){
		sum+=num1(i,x-1,cnt+a[i],max(maxn,a[i]))%998244353;
	}
	return sum%998244353;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[3]>a[1]+a[2]){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=num1(0,i,0,0)%998244353;
		}
		cout<<ans;
	}
    return 0;
}
