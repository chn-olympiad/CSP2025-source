#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,s,w,c,r,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s;
		a[i]=s;
	}
	w=a[1];
	for(int j=1;j<=m*n-1;j++){
		if(a[j]<a[j+1]){
			sum=a[j];
			a[j]=a[j+1];
			a[j+1]=sum;
		}
	}
	for(int k=1;k<=m*n;k++){
		if(a[k]==w){
			w=k;
		}
	}
	if(w%n==0){
		c=w/n;
	}
	else{
		c=w/n+1;
	}
	if(c%2==1){
		r=w-(c-1)*n;
	}
	else{
		r=c*n-w+1;
	}
	cout<<c<<" "<<r;
}
