#include<bits/stdc++.h>
using namespace std;
long long a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long  n,m,s,c,r;
	cin>>n>>m;
	long long sum=n*m;
	for(int i=1; i<=sum; i++){
		cin>>a[i];
	}
	s=a[1];
	for(int i=1; i<=sum-1; i++){
		for(int j=i+1; j<=sum; j++){
			if(a[i]<a[j]){
				long long x=a[i];
				a[i]=a[j];
				a[j]=x;
			}
		}
	}
	for(int i=1; i<=sum; i++){
		if(a[i]==s){
			c=ceill(1.0*i/n);
			if(c==1){
				r=i;
			}
			else if(c%2==1){
				r=i%n;
			}else{
				r=n-(i%n)+1;
			}
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
