#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n=0,m=0;
	cin>>n>>m;
	long long r[n*m+10000];
	for(int i=1;i<=n*m;i++){
		cin>>r[i];
	}
	long long x=r[1],y=0,a=0,b=0;
	sort(r,r+m*n+1);
	long long z[n*m+1];
	for(int i=1;i<=n*m;i++){
		z[i]=r[n*m+1-i];
	}
	for(int i=1;i<=n*m;i++){
		if(z[i]==x){
			y=i;
		}
	}
	if(y%n==0){
		a=y/n;
		if(a%2==1){
			b=n;
		}else{
			b=1;
		}
	}else{
		a=y/n+1;
		if(a%2==1){
			b=y%n;
		}else{
			b=m-y%n+1;
		}
	}
	cout<<a<<" "<<b;
	return 0;
}
