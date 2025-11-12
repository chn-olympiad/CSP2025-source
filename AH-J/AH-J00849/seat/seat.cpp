#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
long long a[10010];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			x=a[i];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	long long c,r,num;
	for(long long i=1;i<=n*m;i++){
		if(a[i]==x){
			num=i;
			break;
		}
	}
	if(num%n==0){
		c=num/n;
	}else{
		c=num/n+1;
	}
	if(c%2==1){
		if(num%n==0){
			r=n;
		}else{
			r=num%n;
		}
	}else{
		r=n-num%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
