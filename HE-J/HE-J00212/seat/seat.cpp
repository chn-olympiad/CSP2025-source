#include<bits/stdc++.h>
using namespace std;
int ans;
int n,m;
int a[309];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	int oo=a[1];
	sort(a+1,a+1+t);
	for(int i=1;i<=t;i++){
		if(a[i]==oo){
			ans=t-i+1;
		}
	}
	int c,r;
	if(ans%n==0){
		c=ans/n;
		if((ans/n)%2==1){
			r=n;
		}
		else{
			r=1;
		}
	}
	else{
		c=(ans/n)+1;
		if(c%2==0){
			r=n-(ans%n)+1;
		}
		else{
			r=ans%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
