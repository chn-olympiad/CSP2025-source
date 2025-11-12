#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,c,r,a1,a1l;
	cin>>n>>m;
	long long a[n*m+5],b[n*m+5];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	for(int i=1,d;i<=m*n;i++){
		int Max=-1;
		for(int j=1;j<=m*n;j++){
			if(Max<a[j]){
				Max=a[j];
				d=j;
			}
		}
		b[i]=Max;
		a[d]=-1;
	}
	for(int i=1;i<=m*n;i++){
		if(b[i]==a1){
			a1l=i;
		}
		//cout<<b[i]<<" ";
	}
	//cout<<"\n"<<a1l<<"\n";
	if(a1l%n==0){
		c=a1l/n;
	}else{
		c=a1l/n+1;
	}
	if(c%2==0){
		r=n-a1l%n+1;
	}else{
		if(a1l%m==0){
			r=n;
		}else{
			r=a1l%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
//:D