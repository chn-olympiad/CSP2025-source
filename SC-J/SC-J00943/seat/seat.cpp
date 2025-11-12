#include<bits/stdc++.h>
using namespace std;
int n,m,nm;
int a[110],a1;
int b;
int c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	a1=a[1];
	for(int i=1;i<nm;i++){
		for(int j=i;j>0;j--){
			if(a[j]<a[j+1]) swap(a[j],a[j+1]);
		}
	}
	for(int i=1;i<=nm;i++){
		if(a[i]==a1){
			b=i;
		}
	}
	if(b%n==0){
		c=b/n;
		if(c%2==0){
			r=1;
		}else r=n;
	}else{
		c=b/n+1;
		int l=b%n;
		if(c%2==0){	
			r=1+(n-l);
		}else r=l;
	} 
	cout<<c<<" "<<r;
	return 0;
} 