#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100010],r=1,l=1,ans;
long long e(long long x){
	long long sum=0,b[1000],j=0;
	while(x!=0){
		j++;
		b[j]=x%2;
		x/=2;
	}
	for(;j>=1;j--){
		sum=sum*10+b[j];
	}
	return sum;
}
long long z(long long x){
	long long sum=0,k=1;
	while(x!=0){
		sum+=k*(x%10);
		k*=2;
		x/=10;
	}
	return sum;
}
long long yh(long long x,long long y){
	if(y==x)return x;
	x=e(x);
	y=e(y);
	long long sum=0,b[1000],j=0;
	while(x!=0||y!=0){
		j++;
		long long s=x%10,k=y%10;
		if(s==k) b[j]=0;
		else b[j]=1;
		x/=10;
		y/=10;
	}
	for(;j>=1;j--){
		sum=sum*10+b[j];
	}
	return z(sum);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=a[1];
	for(long long i=1;i<=n;i++){
		sum=yh(sum,a[i]);
		if(sum==m){
			ans++;
			sum=a[i+1];
		}
	}
	cout<<ans;
	return 0;
}
