#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.cout","w",stdout);
	int n,m,c,d,r,a[101],b,R;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		R=a[1];
	}
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]>a[j-1]){
				b=a[j-1];
				a[j-1]=a[j];
				a[j-1]=b;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		cout<<a[i]<<" ";
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			if(i%m==0){
				c=i/n;
				d=c*n;
				r=d;
			}else{
				c=i/n+1;
				d=c-1;
				d*=n;
				r=i-d;
			}
		}
	}
	cout<<c<<" "<<r;
return 0;
}
