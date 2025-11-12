#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[5005],maxn;
long long f(long long x,long long y){
	long long s=1;
	for(long long i=x;i<=y;i++){
		s*=i;
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>2*maxn){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		long long sum=0;;
		for(long long i=3;i<=n;i++){
			sum+=f(n-i+1,n)/f(1,i);
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
