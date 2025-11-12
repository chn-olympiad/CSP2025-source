#include<bits/stdc++.h>
using namespace std;
long long n,m,c,r,a[10000010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	long long d=a[1];
	sort(a+1,a+1+len);
	
	int b=0;
	for(int i=1;i<=len;i++){
		if(a[i]==d){
			b=i;
		}
	}
	b=len-b+1;
	if(b%n==0){
		c=b/n;
	}else{
		c=b/n+1;
	}
	if(c%2==0){
		r=n-(b%n-1);
		if(r==0){
			r=1;
		}
	}else{
		r=b%n;
		if(r==0){
			r=n;
		}
	}
	cout<<c<<" "<<r;
} 

