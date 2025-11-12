#include <bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,q=0,r,x,y;
	cin>>n>>m;
	p=m*n;
	b[1]=1;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	for(int i=1;i<=p;i++){
		for(int j=1;j<p;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
			}
		}
	}
	for(int i=1;i<=p;i++){
		if(b[i]==1){
			r=i;
		}
	}
	x=(r-1)/m+1;
	if(x%2==1){
		if(r%n==0)
			y=n;
		else
			y=r%n;
	}else{
		if(r%n==0)
			y=0;
		else
			y=(n+1)%(r%n);
	}
	cout<<x<<" "<<y;
	return 0;
} 
