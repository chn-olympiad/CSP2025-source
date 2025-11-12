#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b[N],sum,num,s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		b[s]=a[i];
		s++;
	}
	for(int i=1;i<=n*m;i++){
		if(num==b[i])sum=i;
	}
	int l;
	if(sum%n!=0)l=(sum+n-1)/n;
	else if(sum%n==0)l=sum/n;
	int r;
	if(l%2==1){
	r=sum-(l-1)*n;
}
	else if(l%2==0){
	r=n*m-(m-1)*n;
	}
	cout<<l<<" "<<r;
	
	return 0;
}

