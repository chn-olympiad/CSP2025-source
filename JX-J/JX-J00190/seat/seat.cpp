#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n*m]={};
	cin>>a[1];
	long long d=a[1];
	for(long long i=2;i<=n*m;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n*m;i++){
		for(long long j=i;j<=n*m;j++){
			if(a[i]<a[j]){
				int b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	long long e;
	double x;
	for(long long i=1;i<=n*m;i++) if(a[i]==d) e=i;
	if(e%n) x=e/n+1;
	else x=e/n;
	int c=x;
	cout<<c<<' ';
	int y;
	if(c%2){
		if(e%m==0) y=m;
		else y=e-m*(e/m);
	}else{
		if(e%m==0) y=1;
		else if((e-1)%m==0) y=m;
		else if((e+1)%m==0) y=2;
		else y=(e+1)-m*(e/m);
	}
	cout<<y;
	return 0;
}
