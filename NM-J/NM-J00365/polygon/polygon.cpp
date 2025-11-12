#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
bool check(long long s){
	long long l=0,x=0,q=0,i;
	for(i=1;i<=n;i++)if(s&(1<<i)){
		l+=a[i];
		x=max(x,a[i]);
		q++;
	}
	//cout<<s<<' '<<q<<' '<<l<<' '<<x<<endl;
	return (q>=3)&&(l>2*x);
}
long long fact(long long x){
	return (x*(fact(x-1)%998244353))%998244353;
}
long long c(long long m,long long p){
	if(fact(m)%998244353==0)return 0;
	if(fact(p-m)%998244353==0)return 0;
	return (fact(p)%998244353)/((fact(m)%998244353)*(fact(p-m)%998244353));
}
int main(){
	long long i,j=0;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(flag){
		for(i=3;i<=n;i++){
			j=(j+c(i,n))%998244353;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(i=0;i<(1<<(n+1));i+=2)if(check(i))j++;
	cout<<j;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
