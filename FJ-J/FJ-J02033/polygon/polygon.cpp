#include<bits/stdc++.h>
using namespace std;
long long n,a[5050];
bool b=1;
long long a3(long long x){
	long long c=0;
	for(int i=1;i<=x;i++){
		c+=i;
	}
	if(x!=1)return (a3(x-1)+c)%998244353;
	return 1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)b=0;
	}
	if(n==3){
		sort(a+1,a+1+n);
		if(a[3]<a[2]+a[1])cout<<1;
		else cout<<0;
	}
	else if(b){
		long long sum=a3(n-2),abcd=1;
		for(int i=1;i<n-2;i++){
			sum+=a3(n-i-2)*abcd;
			abcd*=2;
		}
		cout<<sum;
	}
	return 0;
}
